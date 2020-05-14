#include <iostream>

//I want to record the number of cars that drive past my house each day for five
//consecutive days, and calculate the average of these numbers.Create an integer
//array to store these five numbers, and then write code to calculate the average of
//these numbers.Execute your code using the sample data 34, 58, 57, 32, 43. Verify
//that you get the correct answer of 44.8.

int main(int argc, char* argv[])
{
	int intArray[5] = { 34, 58, 57, 32, 43 };

	double average = 0;
	for (int i = 0; i < 5; ++i)
		average += intArray[i];
	average /= 5;

	std::cout << "Average per day: " << average;


	std::cin.get();
	return 0;
}