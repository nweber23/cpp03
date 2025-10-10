#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== FragTrap/ScavTrap/ClapTrap comprehensive tester ===\n\n";

	{
		std::cout << "-- Construction chaining (observe order) --\n";
		FragTrap frag("Frodo");
		ScavTrap scav("Samwise");
		ClapTrap clap("Bilbo");
		std::cout << "\n-- Basic actions (attack, damage, repair, special) --\n";
		frag.attack("an orc");
		frag.takeDamage(20);
		frag.beRepaired(10);
		frag.highFivesGuys();
		std::cout << "\n-- Copy & assignment --\n";
		FragTrap fragCopy(frag);
		FragTrap fragAssigned;
		fragAssigned = frag;
		std::cout << "\n-- Energy exhaustion test (will run many attacks) --\n";
		for (int i = 0; i < 105; ++i)
			frag.attack("training dummy");
		std::cout << "\n-- Death and repair prevention --\n";
		fragCopy.takeDamage(200);
		fragCopy.beRepaired(10);
		std::cout << "\n-- ScavTrap special behaviour --\n";
		scav.guardGate();
		scav.attack("intruder");
		std::cout << "\n-- ClapTrap basic checks --\n";
		clap.attack("target");
		clap.takeDamage(5);
		clap.beRepaired(3);
		std::cout << "\n-- End of local scope: destructors for frag, scav, clap will run (check order) --\n";
	}
	std::cout << "\n=== Tester finished ===\n";
	return 0;
}