#include "BvpOde.hpp"
#include <fstream>
#include <cassert>

BvpOde::BvpOde(const BvpOde& otherBvpOde)
{
	// dummy private copy constructor
	// setting dummy values 
	mpOde = NULL;
	mpBconds = NULL;
	mNumNodes = 0;
	mpGrid = NULL;
	mpSolVec = NULL;
	mpRhsVec = NULL;
	mpLhsMat = NULL;
	mpLinearSystem = NULL;
	mFilename = "";
}

BvpOde::BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes)
{
	assert(pOde->mCoeffOfUxxIsSet && pOde->mCoeffOfUxIsSet && pOde->mCoeffOfUIsSet
		&& pOde->mpRhsFuncIsSet && pOde->mXminIsSet && pOde->mXmaxIsSet);

	mpOde = pOde; //SecondOrderOde*
	mpBconds = pBcs; //BoundaryConditions*
	mNumNodes = numNodes; //int
	mpGrid = new FiniteDifferenceGrid(mNumNodes, mpOde->mXmin, mpOde->mXmax); //FiniteDifferenceGrid*
	mpSolVec = new Vector(mNumNodes); //Vector*
	mpRhsVec = new Vector(mNumNodes); //Vector*
	mpLhsMat = new Matrix(mNumNodes, mNumNodes); //Matrix*
	mpLinearSystem = NULL; //LinearSystem*
	mFilename = "";
}

BvpOde::~BvpOde()
{// deallocate all the dynamic allocated memory
	delete mpGrid;
	delete mpSolVec;
	delete mpRhsVec;
	delete mpLhsMat;
	delete mpLinearSystem;
}

void BvpOde::PopulateMatrix()
{
	// interior values, central finite difference
	double alpha;
	double beta;
	double gamma;
	for (int i = 2; i <= mNumNodes-1; ++i)
	{
		alpha = (2 * mpOde->mCoeffOfUxx) /
				((mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 2].coordinate) *
				(mpGrid->mNodes[i - 1].coordinate - mpGrid->mNodes[i - 2].coordinate)) -
				(mpOde->mCoeffOfUx) / (mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 2].coordinate);
		
		beta = (-2 * mpOde->mCoeffOfUxx) /
				((mpGrid->mNodes[i - 1].coordinate - mpGrid->mNodes[i - 2].coordinate) *
				(mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 1].coordinate)) + mpOde->mCoeffOfU;

		gamma = (2 * mpOde->mCoeffOfUxx) /
			((mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 2].coordinate) *
				(mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 1].coordinate)) +
			(mpOde->mCoeffOfUx) / (mpGrid->mNodes[i].coordinate - mpGrid->mNodes[i - 2].coordinate);

		(*mpLhsMat)(i, i - 1) = alpha;
		(*mpLhsMat)(i, i) = beta;
		(*mpLhsMat)(i, i + 1) = gamma;
	}
}

void BvpOde::PopulateVector()
{
	// interior values
	for (int i = 2; i < mNumNodes; ++i)
	{
		(*mpRhsVec)(i) = mpOde->mpRhsFunc(mpGrid->mNodes[i - 1].coordinate);
	}
}

void BvpOde::ApplyBoundaryConditions()
{
	// left hand side boundary, matrix
	if (mpBconds->mLhsBcIsDirichlet)
	{
		(*mpLhsMat)(1, 1) = 1;
	}
	else if (mpBconds->mLhsBcIsNeumann)
	{//Forward finite difference
		(*mpLhsMat)(1, 1) = -1.0 / (mpGrid->mNodes[1].coordinate - mpGrid->mNodes[0].coordinate); //-1/(x2-x1)
		(*mpLhsMat)(1, 2) = 1.0 / (mpGrid->mNodes[1].coordinate - mpGrid->mNodes[0].coordinate); // 1/(x2-x1)
	}

	// right hand side boundary, matrix
	if (mpBconds->mRhsBcIsDirichlet)
	{
		(*mpLhsMat)(mNumNodes, mNumNodes) = 1;
	}
	else if (mpBconds->mRhsBcIsNeumann)
	{//Backward finite difference
		(*mpLhsMat)(mNumNodes, mNumNodes - 1) = -1.0 /
			(mpGrid->mNodes[mNumNodes - 1].coordinate - mpGrid->mNodes[mNumNodes - 2].coordinate); //-1/(xN-x(N-1))
		(*mpLhsMat)(mNumNodes, mNumNodes) = 1.0 /
			(mpGrid->mNodes[mNumNodes - 1].coordinate - mpGrid->mNodes[mNumNodes - 2].coordinate); // 1/(xN-x(N-1))
	}

	// boundary values, vector
	(*mpRhsVec)(1) = mpBconds->mLhsBcValue;
	(*mpRhsVec)(mNumNodes) = mpBconds->mRhsBcValue;
}

void BvpOde::Solve()
{
	PopulateMatrix();
	PopulateVector();
	ApplyBoundaryConditions();
	mpLinearSystem = new LinearSystem((*mpLhsMat), (*mpRhsVec));
	(*mpSolVec) = mpLinearSystem->Solve();

	/*std::cout << (*mpLhsMat) << "\n\n";
	std::cout << (*mpRhsVec) << "\n\n";
	std::cout << (*mpSolVec) << "\n\n";*/
}

void BvpOde::SetFilename(const std::string& name)
{
	mFilename = name;
}

void BvpOde::WriteSolutionFile()
{
	if (mFilename.empty())
	{
		std::cout << "Set file name: ";
		std::cin >> mFilename;
	}
	std::ofstream writeSolutionToFile(mFilename);
	assert(writeSolutionToFile.is_open());
	writeSolutionToFile.setf(std::ios::scientific);
	writeSolutionToFile.setf(std::ios::showpos);
	writeSolutionToFile.precision(10);
	for (int i=1; i<= mNumNodes;++i)
		writeSolutionToFile << mpGrid->mNodes[i-1].coordinate << '\t' << (*mpSolVec)(i) << '\n';
	writeSolutionToFile.close();
}

void BvpOde::SetGrid(std::vector<double> inputCoordVec)
{
	assert(fabs(inputCoordVec[0] - mpOde->mXmin) < 1e-16);
	assert(fabs(inputCoordVec[inputCoordVec.size() - 1] - mpOde->mXmax) < 1e-16);

	//resize the grid
	mpGrid->SetGrid(inputCoordVec);
	mNumNodes = inputCoordVec.size();

	// allocate new system vectors and matrix
	delete mpSolVec;
	delete mpRhsVec;
	delete mpLhsMat;
	mpSolVec = new Vector(mNumNodes);
	mpRhsVec = new Vector(mNumNodes);
	mpLhsMat = new Matrix(mNumNodes, mNumNodes);
}