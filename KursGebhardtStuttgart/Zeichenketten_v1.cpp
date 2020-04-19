#include <iostream>
#include "ZeichenketteV1.h"

Zeichenkette::Zeichenkette(const char* c_string)
{
	// zaehle zeichen in c string
	int i = 0;
	while (c_string[i] != '\0') i++;
	anzZeich = i;
	if (anzZeich > 0)
	{
		// kopiere string
		z = new char[anzZeich];
		for (i = 0; i < anzZeich; i++) z[i] = c_string[i];
	}
	else z = new char[1]; // damit leere zeichenketten bezueglich zerstoerung konsistent sind .
}

Zeichenkette::Zeichenkette(const Zeichenkette& Z)
{
	if (Z.anzZeich > 0)
	{
		anzZeich = Z.anzZeich;
		// kopiere String
		z = new char[anzZeich];
		for (int i = 0; i < anzZeich; i++) z[i] = Z.z[i];
	}
	else
	{
		anzZeich = 0;
		z = new char[1];
	}
}

Zeichenkette::Zeichenkette(const char C_Char, int num = 1)
{
	anzZeich = num; // weil ein char
	z = new char[num]; // memory allocation
	for (int i = 0; i < num; i++)
		z[i] = C_Char; // zuweisung
}

void Zeichenkette::zeige() const
{
	std::cout << "Zeichenkette: " << '"';
	if (anzZeich > 0)
		for (int i = 0; i < anzZeich; i++) std::cout << z[i];
	std::cout << '"' << " hat ";
	std::cout << anzZeich << " Zeichen.\n";
}

int Zeichenkette::laenge() const
{
	return anzZeich;
}

int Zeichenkette::enthaelt(Zeichenkette& x)
{
	if (x.anzZeich == 0 || x.anzZeich > anzZeich)
		return 0;

	int zeichCtr;
	int enthaeltCtr = 0;
	for (int i = 0; i < anzZeich; i++)
	{
		if (z[i] == x.z[0])
		{
			zeichCtr = 1; //erster Zeichen bereits abgeglichen
			for (int j = 1; j < x.anzZeich; j++)
				if (z[i + j] == x.z[j]) //Abgleich weiterer Zeichen
					zeichCtr++;
			
			if (zeichCtr == x.anzZeich) //Alle Zeichen von x wurden in z gefunden
				enthaeltCtr++;
		}
	}
	return enthaeltCtr;
}

int main()
{
	Zeichenkette a;
	Zeichenkette b("Hello World");
	Zeichenkette c(b);
	Zeichenkette d('x');
	Zeichenkette d2("xx");
	Zeichenkette e('x', 5);
	Zeichenkette f("Hexxxllo Wxorld");
	a.zeige();
	b.zeige();
	c.zeige();
	d.zeige();
	d2.zeige();
	e.zeige();
	f.zeige();
	std::cout << "Laenge von a ist " << a.laenge() << std::endl;
	std::cout << "Laenge von b ist " << b.laenge() << std::endl;
	std::cout << "Laenge von c ist " << c.laenge() << std::endl;
	std::cout << "Laenge von d ist " << d.laenge() << std::endl;
	std::cout << "Laenge von e ist " << e.laenge() << std::endl;

	std::cout << "e enthaelt d2 " << e.enthaelt(d2) << " mal" << std::endl;
	std::cout << "f enthaelt d2 " << f.enthaelt(d2) << " mal"<< std::endl;
	

	std::cin.get();
}