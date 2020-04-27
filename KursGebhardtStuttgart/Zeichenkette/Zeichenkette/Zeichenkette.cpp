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
		z = new char[anzZeich+1];
		for (i = 0; i < anzZeich; i++) z[i] = c_string[i];
		z[anzZeich] = 0;
	}
	else 
		z = new char[1]; // damit leere zeichenketten bezueglich zerstoerung konsistent sind .
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
	z = new char[num+1]; // memory allocation
	for (int i = 0; i < num; i++)
		z[i] = C_Char; // zuweisung
	z[num] = 0;
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

	for (int i = 0; i < obj.anzZeich+1; i++)
		z[i] = obj.z[i];

	return *this;
}

Zeichenkette Zeichenkette::operator + (const Zeichenkette obj)
{
	char* tmpChar = new char[anzZeich + obj.anzZeich + 1];
	for (int i = 0; i < anzZeich; ++i)
		tmpChar[i] = z[i];
	for (int j = anzZeich; j < anzZeich + obj.anzZeich; ++j)
		tmpChar[j] = obj.z[j - anzZeich];
	tmpChar[anzZeich + obj.anzZeich] = 0;
	return Zeichenkette(tmpChar);
}

void Zeichenkette::operator += (const Zeichenkette& obj)
{
	char* tmpChar = new char[anzZeich + obj.anzZeich];
	for (int i = 0; i < anzZeich; ++i)
		tmpChar[i] = z[i];
	for (int j = anzZeich; j < anzZeich + obj.anzZeich; ++j)
		tmpChar[j] = obj.z[j - anzZeich];

	delete[] z;

	char* z = new char[anzZeich + obj.anzZeich];

	for (int i = 0; i < anzZeich + obj.anzZeich; ++i)
		z[i] = tmpChar[i];

	delete[] tmpChar;
	anzZeich += obj.anzZeich;
}

bool Zeichenkette::operator != (const Zeichenkette& obj)
{
	if (anzZeich != obj.anzZeich)
		return 1;
	for (int i = 0; i < anzZeich; i++)
		if (z[i] != obj.z[i])
			return 1;
	return 0;
}

bool Zeichenkette::operator == (const Zeichenkette& obj)
{
	if (anzZeich != obj.anzZeich)
		return 0;
	for (int i = 0; i < anzZeich; i++)
		if (z[i] != obj.z[i])
			return 0;
	return 1;
}

bool Zeichenkette::operator < (const Zeichenkette& obj)
{
	if (anzZeich < obj.anzZeich)
		return 1;
	else
		return 0;
}

bool Zeichenkette::operator <= (const Zeichenkette& obj)
{
	if (anzZeich <= obj.anzZeich)
		return 1;
	else
		return 0;
}

bool Zeichenkette::operator > (const Zeichenkette& obj)
{
	if (anzZeich > obj.anzZeich)
		return 1;
	else
		return 0;
}

bool Zeichenkette::operator >= (const Zeichenkette& obj)
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
	if (this->enthaelt(obj) != 0)
	{
		int idx = this->enthaeltIdx(obj);
		char* tmpChar = new char[anzZeich - obj.anzZeich];
		for (int i = 0; i < idx; i++)
			tmpChar[i] = z[i];
		for (int i = idx; i < anzZeich; i++)
		{
			tmpChar[i] = z[i + obj.anzZeich];
			if (i >= anzZeich - obj.anzZeich) continue;
		}
		return Zeichenkette(tmpChar);
	}
	return *this;
}

void Zeichenkette::operator -= (Zeichenkette& obj)
{
	if (this->enthaelt(obj) != 0)
	{
		int idx = this->enthaeltIdx(obj);
		for (int i = idx; i < anzZeich; i++)
		{
			z[i] = z[i + obj.anzZeich];
			if (i >= anzZeich - obj.anzZeich) continue;
		}
	anzZeich -= obj.anzZeich;	
	}
}

int Zeichenkette::operator / (Zeichenkette& obj)
{
	return this->enthaelt(obj);
}

int Zeichenkette::operator % (Zeichenkette& obj)
{
	return this->enthaeltIdx(obj);
}

Zeichenkette Zeichenkette::operator | (short num)
{
	einfuegepunkt = ((num >= 0) && (num <= anzZeich)) ? num : -1;
	return *this;
}

Zeichenkette Zeichenkette::operator * (const Zeichenkette& obj)
{
	if (einfuegepunkt == -1)
		return *this;
	
	char* tmpChar = new char[anzZeich + obj.anzZeich + 1];
	
	for (int i = 0; i < einfuegepunkt; ++i)
		tmpChar[i] = z[i];
	for (int i = einfuegepunkt; i < einfuegepunkt + obj.anzZeich; ++i)
		tmpChar[i] = obj.z[i - einfuegepunkt];
	for (int i = einfuegepunkt + obj.anzZeich; i < anzZeich + obj.anzZeich; ++i)
		tmpChar[i] = z[i- obj.anzZeich];
	tmpChar[anzZeich + obj.anzZeich] = 0;

	return Zeichenkette(tmpChar);
}

Zeichenkette::operator std::string()
{
	std::string zString = z;
	return zString;
}

int Zeichenkette::operator () (char x, short position = 0)
{
	if (position < 0 || position >= anzZeich)
		return -1;

	for (int i = position; i < anzZeich; i++)
		if (z[i] == x)
			return i;

	return -1;
}
// Ubung zum Operator()
// Schreibe einen Funktionsaufruf - Operator fur die Klasse Zeichenkette, der ab einer Postion in der Zeichenkette nach einem Zeichen vom Typ char sucht und dessen Position zuruckgibt oder, falls nicht gefunden, -1 liefert.

int main()
{
	Zeichenkette a("Hello World ");
	std::cout << "a:  "; a.zeige();
	Zeichenkette b;
	b = a;
	std::cout << "b:  "; b.zeige();
	Zeichenkette c;
	c = a + "!";
	std::cout << "c:  "; c.zeige();

	Zeichenkette d("Hello ");
	Zeichenkette e1("rld");
	Zeichenkette e("World record");
	Zeichenkette f("John Doe");
	Zeichenkette g("ohn");
	d += e1;
	std::cout << "d:  "; d.zeige();
	e -= e1;
	std::cout << "e:  "; e.zeige();
	e -= d;
	std::cout << "e:  "; e.zeige();
	f = f - g;
	std::cout << "f:  "; f.zeige();
	f = f - c;
	std::cout << "f:  "; f.zeige();
	f = c - e1;
	std::cout << "f:  "; f.zeige();


	std::cout << "===================================" << std::endl;
	std::cout << "a != b \t" << (a != b) << std::endl;
	std::cout << "a != c \t" << (a != c) << std::endl;
	std::cout << "a == b \t" << (a == b) << std::endl;
	std::cout << "a == c \t" << (a == c) << std::endl;
	std::cout << "a < b \t" << (a < b) << std::endl;
	std::cout << "a < c \t" << (a < c) << std::endl;
	std::cout << "a <= b \t" << (a <= b) << std::endl;
	std::cout << "a <= c \t" << (a <= c) << std::endl;
	std::cout << "a > b \t" << (a > b) << std::endl;
	std::cout << "a > c \t" << (a > c) << std::endl;
	std::cout << "a >= b \t" << (a >= b) << std::endl;
	std::cout << "a >= c \t" << (a >= c) << std::endl;
	std::cout << "c / a \t" << (c / a) << std::endl;
	std::cout << "e / f \t" << (e / f) << std::endl;
	std::cout << "c % a \t" << (c % a) << std::endl;
	std::cout << "e % f \t" << (e % f) << std::endl;

	std::cout << "===================================" << std::endl;
	Zeichenkette h("Hello "); h.zeige();
	Zeichenkette k("World"); k.zeige();
	std::cout << "h | 0; h * k \t"; h | 0; (h * k).zeige();
	std::cout << "h | 3; h * k \t"; h | 3; (h * k).zeige();
	std::cout << "h | 6; h * k \t"; h | 6; (h * k).zeige();
	std::cout << "h | -6; h * k \t"; h | -4; (h * k).zeige();
	std::cout << "h | 15; h * k \t"; h | 15; (h * k).zeige();

	std::cout << (std::string)a << std::endl;
	std::cout << "k('d')     " << k('d') << std::endl;
	std::cout << "k('d',3)   " << k('d',3) << std::endl;
	std::cout << "k('d',8)   " << k('d',8) << std::endl;


	std::cin.get();
}