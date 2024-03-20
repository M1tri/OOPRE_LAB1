#pragma once
#include "Polje.h"
class Trava : public Polje
{
public:
	Trava(bool vidljivost = false): Polje(vidljivost) {}

	int poprskaj(int mlaz) override
	{
		otkriveno = true;

		return 0;
	}

	/*POLJA sadrzaj() override
	{
		return POLJA::TRAVA;
	}*/

	void prikazi() override
	{
		std::cout << std::setw(4) << "i";
	}

	bool operator==(POLJA polje)
	{
		return polje == POLJA::TRAVA;
	}


};

