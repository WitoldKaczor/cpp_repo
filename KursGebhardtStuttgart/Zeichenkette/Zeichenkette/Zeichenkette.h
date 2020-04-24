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
	int enthaelt(Zeichenkette& z); //wie haeufig die Zeichenkette z in einer Zeichenkette enthalten ist

private:
	int anzZeich;
	char* z;
};
#endif