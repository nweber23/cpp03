#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("CL4P-TP");
	ClapTrap b("FR4G-TP");

	a.attack("an enemy");
	b.takeDamage(3);
	b.beRepaired(5);

	// Deplete energy
	for (int i = 0; i < 11; ++i)
		a.attack("a dummy");

	// Damage to zero
	b.takeDamage(20);
	b.beRepaired(2); // should not work when HP == 0

	return 0;
}