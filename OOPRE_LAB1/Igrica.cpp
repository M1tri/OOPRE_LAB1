#include "Igrica.h"

void Igrica::pokreni()
{
	bool fast = false;

	while (!kraj())
	{
		gadjaj();

		if (!fast)
		{
			if (std::cin.get() == 0)
				fast = true;
		}
	}

	std::cout << "Broj poena: " << livada.broj_ruza() << '\n';
}

void Igrica::gadjaj()
{
	livada.prskaj();
}

bool Igrica::kraj()
{
	return livada.kraj();
}