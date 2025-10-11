#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_name = "Unnamed";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed (default)" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " copy constructed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " copy-assigned" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructed" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " can't attack, it has no hit points left" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "FragTrap " << _name << " can't attack, it has no energy left" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "FragTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage! "
			<< "(EP left: " << _energyPoints << ")" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a high five! 🙌" << std::endl;
}