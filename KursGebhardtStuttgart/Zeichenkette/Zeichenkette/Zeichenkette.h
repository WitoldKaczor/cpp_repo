#ifndef Zeichenkette_h
#define Zeichenkette_h

#include <iostream>

class Zeichenkette
{
public:
	Zeichenkette() : anzZeich(0) { z = new char[1]; } // Defaultkonstruktor
	Zeichenkette(const char* C_String);
	Zeichenkette(const Zeichenkette& Z); // Copykonstruktor
	Zeichenkette(const char C_Char, int num);
	~Zeichenkette() { delete[] z; } // Destruktor
	void zeige() const; // Gibt String auf stdout aus mit Kommentar und Zeilenvorschub.
	int laenge() const; // Gibt die Laenge von String aus
	int enthaelt(Zeichenkette& x); //wie haeufig die Zeichenkette x in einer Zeichenkette enthalten ist
	int enthaeltIdx(Zeichenkette& x); //Index der ersten Zeichenkette x in einer Zeichenkette

	Zeichenkette& operator = (const Zeichenkette& obj);
	Zeichenkette operator + (const Zeichenkette obj);
	void operator += (const Zeichenkette& obj);
	bool operator != (const Zeichenkette& obj);
	bool operator == (const Zeichenkette& obj);
	bool operator < (const Zeichenkette& obj);
	bool operator <= (const Zeichenkette& obj);
	bool operator > (const Zeichenkette& obj);
	bool operator >= (const Zeichenkette& obj);
	Zeichenkette operator << (int num); //linksbuendiges Padding
	Zeichenkette operator >> (int num); //rechtsbuendiges Padding
	Zeichenkette operator || (int num); //zentriertes Padding
	Zeichenkette operator - (Zeichenkette& obj);
	void operator -= (Zeichenkette& obj);
	int operator / (Zeichenkette& obj);
	int operator % (Zeichenkette& obj);
	Zeichenkette operator | (short num); // a | 4 setzt Einfugepunkt vor Zeichen 4, gibt wieder a zuruck
	Zeichenkette operator * (const Zeichenkette& obj); // a * b fügt Zeichenkette b in a am Einfügepunkt ein und gibt Resultat zurück
	operator std::string ();
	int operator () (char x, short position);

private:
	int anzZeich;
	char* z;
	short einfuegepunkt = -1;
};
#endif