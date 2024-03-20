#pragma once

#include <iostream>
#include <iomanip>

enum class POLJA
{
	TRAVA,
	SEME_RUZE,
	RUZA,
	TROJANKSA_RUZA,
	JAJE_PUZA,
	PUZ,
	TROJANSKI_PUZ
};

class Polje
{
protected:
	bool otkriveno;

public:
	Polje(bool vidljivost = false) : otkriveno(vidljivost) {}

	virtual int poprskaj(int mlaz) = 0;
	//virtual POLJA sadrzaj() = 0;
	virtual void prikazi() = 0;

	virtual bool operator==(POLJA polje)
	{
		return this->operator==(polje);
	}

	bool vidljivo() const
	{
		return otkriveno;
	}
};

