#include "Quadrat.h"

void Quadrat::initialisieren(double x)
{ 
	Rechteck::setLaenge(x);
	Rechteck::setBreite(x);
}

void Quadrat::setBreite(double x)
{
	Rechteck::setLaenge(x);
	Rechteck::setBreite(x);
}

void Quadrat::setLaenge(double x)
{
	Rechteck::setLaenge(x);
	Rechteck::setBreite(x);
}