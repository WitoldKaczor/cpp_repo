#include <iostream>
#include "Rechteck.h"

void Rechteck::initialisieren(double x, double y) { a = x; b = y; }

double Rechteck::calcFlaeche() { return a * b; };

double Rechteck::calcUmfang() { return 2 * a + 2 * b; };

double Rechteck::getLaenge() const { return a; };

double Rechteck::getBreite() const { return b; };

void Rechteck::setLaenge(double x) { a = x; };

void Rechteck::setBreite(double y) { b = y; };


void Rechteck::zeige()
{
	std::cout << "Laenge : \t" << this->getLaenge() << "\n";
	std::cout << "Breite : \t" << this->getBreite() << "\n";
	std::cout << "Flaeche : \t" << this->calcFlaeche() << "\n";
	std::cout << "Umfang : \t" << this->calcUmfang() << "\n";
};