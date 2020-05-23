#include <iostream>

class AbstractPerson
{
public:
	AbstractPerson() { std::cout << "constr AbstractPerson\n"; }
	virtual ~AbstractPerson() { std::cout << "destr AbstractPerson\n"; }
	virtual void Print() = 0;
};

class Mother : public AbstractPerson
{
public:
	Mother() { std::cout << "constr Mother\n"; }
	~Mother() { std::cout << "destr Mother\n"; }
	void Print() { std::cout << "Mother\n"; }
};

class Daughter : public Mother
{
public:
	Daughter() { std::cout << "constr Daughter\n"; }
	~Daughter() { std::cout << "destr Daughter\n"; }
	void Print() { std::cout << "Daughter\n"; }
};


int main(int argc, char* argv[])
{
	AbstractPerson* p_mother = new Mother;
	AbstractPerson* p_daughter = new Daughter;
	p_mother->Print();
	p_daughter->Print();
	delete p_mother;
	delete p_daughter;
	

	std::cin.get();
	return 0;
}