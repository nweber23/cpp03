#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	{
		std::cout << "-- Construction (only one ClapTrap constructed due to virtual inheritance) --\n";
		DiamondTrap d1("Ava");
		std::cout << "\n-- Inherited abilities (from ScavTrap and FragTrap) --\n";
		d1.attack("training dummy");
		d1.highFivesGuys();
		d1.guardGate();
		d1.whoAmI();
		std::cout << "\n-- Energy exhaustion (EP starts at 50 from ScavTrap) --\n";
		for (int i = 0; i < 55; ++i)
			d1.attack("goblin");
		std::cout << "\n-- Death and repair prevention (HP starts at 100 from FragTrap) --\n";
		d1.takeDamage(150);
		d1.beRepaired(10);
	}
	std::cout << "\n-- Copy and assignment semantics --\n";
	{
		DiamondTrap src("Ruby");
		src.attack("orc");
		src.whoAmI();
		std::cout << "\nCopy construction:\n";
		DiamondTrap cpy(src);
		cpy.whoAmI();
		std::cout << "\nCopy assignment:\n";
		DiamondTrap asg;
		asg = src;
		asg.whoAmI();
		std::cout << "\nVerify behavior after copies (attack uses ScavTrap, stats preserved):\n";
		cpy.attack("skeleton");
		asg.attack("zombie");
	}
	return 0;
}