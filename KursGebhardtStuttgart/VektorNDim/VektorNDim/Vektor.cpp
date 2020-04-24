//Ubung Klasse Vektor
// Schreiben Sie eine Klasse Vektor fur n - dimensionale Vektoren von double - Elementen mit dem Konstruktor Vektor(int n, 	double x = 0) 
// und den Operatoren [] + - * ()  wobei der Operator() den Vektor vernunftig darstellen soll.
#include <iostream>
#include <assert.h>  

class Vektor
{
public:
	Vektor(int n, double x = 0)
	{
		dim = n;
		data = new double[dim];
		for (int i = 0; i < dim; ++i)
		{
			data[i] = x;
			//std::cout << data[i] << std::endl;
		}
	}

	void operator () () 
	{
		std::cout << "( ";
		for (int i = 0; i < dim; ++i)
			std::cout << data[i] << " ";
		std::cout << ")" << std::endl;
	}

	double operator [] (int idx)
	{
		assert(idx < dim && idx >= 0);
		return data[idx];
	}

	Vektor operator + (const Vektor& OtherVec)
	{
		Vektor newVec(dim);
		assert(dim == OtherVec.dim);
		//std::cout << "Dimensionen stimmen ueberein" << std::endl;
		for (int i = 0; i < dim; ++i)
			newVec.data[i] = data[i] + OtherVec.data[i];
		return newVec;
	}

	Vektor operator - (const Vektor& OtherVec)
	{
		Vektor newVec(dim);
		assert(dim == OtherVec.dim);
		//std::cout << "Dimensionen stimmen ueberein" << std::endl;
		for (int i = 0; i < dim; ++i)
			newVec.data[i] = data[i] - OtherVec.data[i];
		return newVec;
	}

	Vektor operator * (const Vektor& OtherVec)
	{
		Vektor newVec(dim);
		assert(dim == OtherVec.dim);
		//std::cout << "Dimensionen stimmen ueberein" << std::endl;
		for (int i = 0; i < dim; ++i)
			newVec.data[i] = data[i] * OtherVec.data[i];
		return newVec;
	}


private:
	double* data = nullptr;
	int dim = -1;
};


int main()
{
	Vektor vec(3, 5);
	Vektor vec2(3, 3);
	Vektor vec3(2);

	vec();
	vec2();
	vec3();

	std::cout << vec[0] << std::endl;
	//std::cout << vec[3] << std::endl; // führt zum Fehler

	vec = vec + vec2;
	vec();
	//vec = vec + vec3; // führt zum Fehler
	
	vec = vec * vec2;
	vec();
	//vec = vec * vec3; // führt zum Fehler

	vec = vec - vec2;
	vec();
	//vec = vec - vec3; // führt zum Fehler
	

	std::cin.get();
}