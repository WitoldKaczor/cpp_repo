#include <iostream>
#include "Zeichenkette.h"
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
	std::cout << anzZeich << " Zeichen." << std::endl;
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

int Zeichenkette::enthaeltIdx(Zeichenkette& x)
{
	if (x.anzZeich == 0 || x.anzZeich > anzZeich)
		return -1;

	int zeichCtr;
	for (int i = 0; i < anzZeich; i++)
	{
		if (z[i] == x.z[0])
		{
			zeichCtr = 1; //erster Zeichen bereits abgeglichen
			for (int j = 1; j < x.anzZeich; j++)
				if (z[i + j] == x.z[j]) //Abgleich weiterer Zeichen
					zeichCtr++;

			if (zeichCtr == x.anzZeich) //Alle Zeichen von x wurden in z gefunden
				return i;
		}
	}
	return -1;
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
	for (int i = 0; i < obj.anzZeich; i++)
		erg.z[i + anzZeich] = obj.z[i];
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

int Zeichenkette::operator < (const Zeichenkette& obj)
{
	if (anzZeich < obj.anzZeich)
		return 1;
	else
		return 0;
}

int Zeichenkette::operator <= (const Zeichenkette& obj)
{
	if (anzZeich <= obj.anzZeich)
		return 1;
	else
		return 0;
}

int Zeichenkette::operator > (const Zeichenkette& obj)
{
	if (anzZeich > obj.anzZeich)
		return 1;
	else
		return 0;
}

int Zeichenkette::operator >= (const Zeichenkette& obj)
{
	if (anzZeich >= obj.anzZeich)
		return 1;
	else
		return 0;
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

Zeichenkette Zeichenkette::operator - (Zeichenkette& obj)
{
	// obj nicht enthalten, keine Substraktion
	if (this->enthaelt(obj) == 0)
		return *this;

	// obj enthalten, obj str aus der aktuellen Instanz löschen
	Zeichenkette erg;
	erg = *this;

	for (int i = this->enthaeltIdx(obj); i < obj.anzZeich + this->enthaeltIdx(obj); i++)
	{
		if (i + obj.anzZeich < erg.anzZeich)
			erg.z[i] = erg.z[i + obj.anzZeich];
		else
		{
			erg.anzZeich = this->anzZeich - obj.anzZeich;
			continue;
		}
	}
	return erg;
}

int Zeichenkette::operator / (Zeichenkette& obj)
{
	return this->enthaelt(obj);
}

int Zeichenkette::operator % (Zeichenkette& obj)
{
	return this->enthaeltIdx(obj);
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


	Zeichenkette e1("World");
	Zeichenkette e("Hello World");
	Zeichenkette f("Hello World");
	e = e - e1;
	e.zeige();
	f = f - c;
	f.zeige();


	std::cout << "a != b " << (a != b) << std::endl;
	std::cout << "a != c " << (a != c) << std::endl;
	std::cout << "a == b " << (a == b) << std::endl;
	std::cout << "a == c " << (a == c) << std::endl;
	std::cout << "a < b " << (a < b) << std::endl;
	std::cout << "a < c " << (a < c) << std::endl;
	std::cout << "a <= b " << (a <= b) << std::endl;
	std::cout << "a <= c " << (a <= c) << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a > c " << (a > c) << std::endl;
	std::cout << "a >= b " << (a >= b) << std::endl;
	std::cout << "a >= c " << (a >= c) << std::endl;
	std::cout << "c / a " << (c / a) << std::endl;
	std::cout << "e / f " << (e / f) << std::endl;
	std::cout << "c % a " << (c % a) << std::endl;
	std::cout << "e % f " << (e % f) << std::endl;

	std::cout << c.enthaeltIdx(a) << std::endl;
	std::cout << f.enthaeltIdx(c) << std::endl;
	std::cout << f.enthaeltIdx(e1) << std::endl;

	
	std::cin.get();
}