#include <iostream>
#include "ZeichenketteV2.h"
#include <algorithm>

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

Zeichenkette& Zeichenkette::operator = (const Zeichenkette& obj)
{
	anzZeich = obj.anzZeich;
	z = new char[obj.anzZeich];

	for (int i = 0; i < obj.anzZeich; i++)
		z[i] = obj.z[i];

	return *this;
}

Zeichenkette Zeichenkette::operator + (const Zeichenkette obj)
{
	Zeichenkette erg;
	erg.anzZeich = anzZeich + obj.anzZeich;
	erg.z = new char[anzZeich + obj.anzZeich];

	for (int i = 0; i < anzZeich; i++)
		erg.z[i] = z[i];
	for (int i = anzZeich; i < anzZeich + obj.anzZeich; i++)
		erg.z[i] = obj.z[i - anzZeich];
	return erg;
}

int Zeichenkette::operator != (const Zeichenkette& obj)
{
	if (anzZeich != obj.anzZeich)
		return 1;
	for (int i = 0; i < anzZeich; i++)
		if (z[i] != obj.z[i])
			return 1;
	return 0;
}

int Zeichenkette::operator == (const Zeichenkette& obj)
{
	if (anzZeich != obj.anzZeich)
		return 0;
	for (int i = 0; i < anzZeich; i++)
		if (z[i] != obj.z[i])
			return 0;
	return 1;
}







Zeichenkette Zeichenkette::operator << (int num) //linksbuendiges Padding
{
	Zeichenkette obj(' ', num);
	if (anzZeich >= num)
		for (int i = 0; i < num; i++)
			obj.z[i] = z[i];
	else // num > anzZeich
		for (int i = 0; i < anzZeich; i++)
			obj.z[i] = z[i];
	return obj;
}

Zeichenkette Zeichenkette::operator >> (int num) //linksbuendiges Padding
{
	Zeichenkette obj(' ', num);
	if (anzZeich >= num)
		for (int i = 0; i < num; i++)
			obj.z[i] = z[i];
	else // num > anzZeich
		for (int i = num - 1; i > (num - anzZeich) - 1; i--)
			obj.z[i] = z[i - (num - anzZeich)];
	return obj;
}

Zeichenkette Zeichenkette::operator || (int num) //zentriertes Padding
{
	Zeichenkette obj(' ', num);
	if (anzZeich >= num)
		for (int i = 0; i < num; i++)
			obj.z[i] = z[i + ((anzZeich - num) / 2)];
	else // num > anzZeich
		for (int i = 0; i < anzZeich; i++)
			obj.z[i + ((num - anzZeich) / 2)] = z[i];
	return obj;
}

int main()
{
	Zeichenkette a("Hello World ");
	a.zeige();
	Zeichenkette b; 
	b = a;
	b.zeige();
	Zeichenkette c;
	c = a + b;
	c.zeige();
	Zeichenkette d("Test ");
	//d += b;
	//d.zeige();

	std::cout << "a!=b " << (a != b) << std::endl;
	std::cout << "a!=c " << (a != c) << std::endl;
	std::cout << "a==b " << (a == b) << std::endl;
	std::cout << "a==c " << (a == c) << std::endl;




	/*Zeichenkette a("Hello World");
	a.zeige();
	Zeichenkette b = a << 5;
	Zeichenkette c = a << 20;
	Zeichenkette d = a >> 5;
	Zeichenkette e = a >> 20;
	Zeichenkette f = a || 5;
	Zeichenkette g = a || 20;
	b.zeige();
	c.zeige();
	d.zeige();
	e.zeige();
	f.zeige();
	g.zeige();*/


	std::cin.get();
}