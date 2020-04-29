#pragma once

class Rechteck
{
public:
	void initialisieren(double x, double y);
	double calcFlaeche();
	double calcUmfang();
	double getLaenge() const;
	double getBreite() const;
	void setLaenge(double x);
	void setBreite(double x);
	void zeige();

private:
	double a;
	double b;
};
