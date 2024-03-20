#pragma once
#include "Polje.h"

class Puz: public Polje
{
public:

	Puz(): Polje() {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	POLJA sadrzaj() override
	{
		return POLJA::PUZ;
	}

	void prikazi() override
	{
		if (otkriveno)
			std::cout << "@";
		else
			std::cout << "i";
	}

};

