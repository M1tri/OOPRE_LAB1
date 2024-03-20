#pragma once

#include "Livada.h"

class Igrica
{
private:
	Livada livada;

public:
	Igrica(std::string file_name): livada(file_name) {}

	void pokreni();
	void gadjaj();
	bool kraj();
};

