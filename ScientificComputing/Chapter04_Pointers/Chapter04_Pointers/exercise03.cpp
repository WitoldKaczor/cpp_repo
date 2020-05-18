//Write code that allocates memory dynamically to two vectors of double precision
//floating point numbers of length 3, assigns values to each of the entries, and then deallocates
//the memory before the code terminates.Extend this code so that it calculates
//the scalar(dot) product of these vectors and prints it to screen before the memory is
//de-allocated. Put the allocation of memory, calculation and de-allocation of memory
//inside a for loop that runs 1,000,000,000 times: if the memory is not de-allocated
//properly your code will use all available resources and your computer may struggle.

#include <iostream>

int main(int argc, char* argv[])
{	
	double scalarProduct = 0;
	int iterNum = 1000000000;
	
	for (int iter = 0; iter < iterNum; ++iter)
	{
		double* vec1 = new double[3];
		double* vec2 = new double[3];
		for (int i = 0; i < 3; ++i)
		{
			vec1[i] = (double)i + 1;
			vec2[i] = (double)i * 4;
			scalarProduct += vec1[i] * vec2[i];
			//std::cout << vec1[i] << "  " << vec2[i] << '\n';
		}
		//std::cout << "Scalar Product = " << scalarProduct;
		delete[] vec1;
		delete[] vec2;
	}

	std::cout << "Done";
	std::cin.get();
	return 0;
}