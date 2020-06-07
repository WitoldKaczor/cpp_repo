#include "BvpOde.hpp"
#include <fstream>
#include <cassert>
#include <iostream>

BvpOde::BvpOde(const BvpOde& otherBvpOde)
{
	// dummy private copy constructor
	// setting dummy values 
	mNumNodesX = 0;
	mNumNodesY = 0;
	mpGrid = NULL;
	mpOde = NULL;
	mpBcs = NULL;
	mpSolVec = NULL;
	mpRhsVec = NULL;
	mpLhsMat = NULL;
	mpLinSys = NULL;
	mFilename = "";
}

BvpOde::BvpOde(PoissonEq* pOde, FiniteDifferenceGrid* pGrid,
	BoundaryConditions* pBcs, int numNodesX, int numNodesY)
{
	mNumNodesX = numNodesX;
	mNumNodesY = numNodesY;
	mpGrid = pGrid;
	mpOde = pOde;
	mpBcs = pBcs;
	mpSolVec = new Vector(numNodesX * numNodesY);
	mpRhsVec = new Vector(numNodesX * numNodesY);
	mpLhsMat = new Matrix(numNodesX * numNodesY, numNodesX * numNodesY);
	mpLinSys = NULL;
	mFilename = "";
}

BvpOde::~BvpOde()
{// deallocate all the dynamic allocated memory
	delete mpSolVec;
	delete mpRhsVec;
	delete mpLhsMat;
	delete mpLinSys;
}

void BvpOde::PopulateMatrix()
{
	// only interior nodes
	double alpha;
	double alphaE;
	double alphaW;
	double alphaN;
	double alphaS;
	double xi, xiE, xiW;
	double yi, yiN, yiS;

	for (int i = 2; i < mNumNodesX; ++i)
		for (int j = 1; j < mNumNodesY-1; ++j)
		{
			xi = mpGrid->mNodes[i + mNumNodesX * j - 1].X;
			xiE = mpGrid->mNodes[(i + 1) + mNumNodesX * j - 1].X;
			xiW = mpGrid->mNodes[(i - 1) + mNumNodesX * j - 1].X;

			yi = mpGrid->mNodes[i + mNumNodesX * j - 1].Y;
			yiN = mpGrid->mNodes[i + mNumNodesX * (j + 1) - 1].Y;
			yiS = mpGrid->mNodes[i + mNumNodesX * (j - 1) - 1].Y;

			alpha = -2.0 / ((xiE - xi) * (xi - xiW)) - 2.0 / ((yiN - yi) * (yi - yiS));
			alphaE = 2.0 / ((xiE - xiW) * (xiE - xi));
			alphaW = 2.0 / ((xiE - xiW) * (xi - xiW));
			alphaN = 2.0 / ((yiN - yiS) * (yiN - yi));
			alphaS = 2.0 / ((yiN - yiS) * (yi - yiS));
			
			(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * j) = alpha;
			(*mpLhsMat)(i + mNumNodesX * j, (i + 1) + mNumNodesX * j) = alphaE;
			(*mpLhsMat)(i + mNumNodesX * j, (i - 1) + mNumNodesX * j) = alphaW;
			(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * (j + 1)) = alphaN;
			(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * (j - 1)) = alphaS;
		}
}

void BvpOde::PopulateVector()
{
	// only interior nodes
	for (int i = 1; i < mNumNodesX - 1; ++i)
		for (int j = 1; j < mNumNodesY - 1; ++j)
		{
			(*mpRhsVec)[i + mNumNodesX * j] = mpOde->mpRhsFunc(
				mpGrid->mNodes[i + mNumNodesX * j].X,
				mpGrid->mNodes[i + mNumNodesX * j].Y);
		}
}

void BvpOde::ApplyBoundaryConditions()
{
	// Vector
	for (int i = 0, j; i < mNumNodesX; ++i) // iterate over x
	{
		j = mNumNodesY - 1; // y max held
		(*mpRhsVec)[i + mNumNodesX * j] = mpBcs->XAtYmax[i];
	}
	for (int i = 0, j; i < mNumNodesX; ++i) // iterate over x
	{
		j = 0; // y min held
		(*mpRhsVec)[i + mNumNodesX * j] = mpBcs->XAtYmin[i];
	}
	for (int j = 1, i; j < mNumNodesY-1; ++j) // iterate over y, without corner nodes
	{
		i = mNumNodesX - 1; // x max held
		(*mpRhsVec)[i + mNumNodesX * j] = mpBcs->YAtXmax[j];
	}
	for (int j = 1, i; j < mNumNodesY-1; ++j) // iterate over y, without corner nodes
	{
		i = 0; // x min held
		(*mpRhsVec)[i + mNumNodesX * j] = mpBcs->YAtXmin[j];
	}
	
	
	// Matrix
	// for all boundary nodes ui = bi -> 1.0 on the matrix diagonal
	for (int i = 1; i < mNumNodesX + 1; ++i)
	{
		int j = 0;
		(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * j) = 1.0;
	}
	for (int i = 1; i < mNumNodesX + 1; ++i)
	{
		int j = mNumNodesY - 1;
		(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * j) = 1.0;
	}
	for (int j = 1; j < mNumNodesY - 1; ++j)
	{
		int i = 1;
		(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * j) = 1.0;
	}
	for (int j = 1; j < mNumNodesY - 1; ++j)
	{
		int i = mNumNodesX;
		(*mpLhsMat)(i + mNumNodesX * j, i + mNumNodesX * j) = 1.0;
	}
}

void BvpOde::Solve()
{
	PopulateMatrix();
	PopulateVector();
	ApplyBoundaryConditions();
	mpLinSys = new LinearSystem((*mpLhsMat), (*mpRhsVec));
	(*mpSolVec) = mpLinSys->Solve();
	
	/*(*mpLhsMat).WriteMatrixToFile("system_matrix.dat");
	(*mpRhsVec).WriteVectorToFile("rhs_vector.dat");
	(*mpSolVec).WriteVectorToFile("sol_vector.dat");*/
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

	for (int i = 1; i <= mNumNodesX * mNumNodesY; ++i)
	{
		writeSolutionToFile << mpGrid->mNodes[i - 1].X << '\t' 
			<< mpGrid->mNodes[i - 1].Y << '\t'
			<< (*mpSolVec)(i) << '\n';
	}
	writeSolutionToFile.close();
}

Vector* BvpOde::OutputSolution() const
{
	return mpSolVec;
}