#pragma once
#include "Polje.h"
class Trojanska_ruza : public Polje
{
public:
	Trojanska_ruza(): Polje() {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	POLJA sadrzaj() override
	{
		return POLJA::TROJANKSA_RUZA;
	}

	void prikazi() override
	{
		if (otkriveno)
			std::cout << "*";
		else
			std::cout << "i";
	}
};

