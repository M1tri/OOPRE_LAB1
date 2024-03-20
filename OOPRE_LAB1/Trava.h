#pragma once
#include "Polje.h"
class Trava : public Polje
{
public:
	Trava(): Polje() {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	POLJA sadrzaj() override
	{
		return POLJA::TRAVA;
	}

	void prikazi() override
	{
		std::cout << "i";
	}

};

