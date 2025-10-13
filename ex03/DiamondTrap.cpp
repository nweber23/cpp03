#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), _name("Unnamed") {
	_hitPoints = 100; // FragTrap
	_energyPoints = 50; // ScavTrap
	_attackDamage = 30; // FragTrap
	std::cout << "DiamondTrap " << _name << " constructed (default)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name  + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = 100; // FragTrap
	_energyPoints = 50; // ScavTrap
	_attackDamage = 30; // FragTrap
	std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :  ClapTrap(other.ClapTrap::_name), ScavTrap(other), FragTrap(other), _name(other._name) {
	_hitPoints = other._hitPoints;
	_energyPoints =  other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << _name << " copy-constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap " << _name << " copy-assigned" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructed" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << " | ClapTrap name: " << ClapTrap::_name << std::endl;
}