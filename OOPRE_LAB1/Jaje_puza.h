#pragma once
#include "Polje.h"
class Jaje_puza : public Polje
{
private:
	int broj = 1;

public:
	Jaje_puza() : Polje() {};

	int poprskaj(int mlaz) override
	{
		otkriveno = false;

		return mlaz + broj;
	}

	POLJA sadrzaj() override
	{
		return POLJA::JAJE_PUZA;
	}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << "0";
		else
			std::cout << "i";
	}

};




