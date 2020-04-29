#pragma once
#include "Rechteck.h"

class Quadrat : public Rechteck
{
public:
	void initialisieren(double x);
	void setLaenge(double x);
	void setBreite(double x);
};