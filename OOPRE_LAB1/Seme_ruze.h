#pragma once
#include "Polje.h"

class Seme_ruze : public Polje
{
private:
	int broj;

public:
	Seme_ruze(int broj) : Polje(), broj(broj) { if (broj < 1 || broj > 2) broj = 1; }

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return mlaz + broj;
	}

	POLJA sadrzaj() override
	{
		return POLJA::SEME_RUZE;
	}


	void prikazi() override
	{
		if (otkriveno)
			std::cout << "o";
		else
			std::cout << "i";
	}

};

