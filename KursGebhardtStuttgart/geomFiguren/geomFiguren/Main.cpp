#include <iostream>
#include "Rechteck.h"
#include "Quadrat.h"


int main()
{
	Rechteck f;
	f.initialisieren(3.8, 7.9);
	f.setBreite(4.5);
	f.setLaenge(9.8);
	f.zeige();
	std::cout << std::endl;

	Quadrat g;
	g.initialisieren(1.9);
	g.setBreite(5);
	g.zeige();
	std::cout << std::endl;
	g.setLaenge(3.4);
	g.zeige();
	

	std::cin.get();
}