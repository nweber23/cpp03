#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap: basic actions ===\n";
	ClapTrap ct("Clappy");
	ct.attack("a training bot");
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.takeDamage(20);
	ct.beRepaired(5);

	std::cout << "\n=== ScavTrap: construction, attack override and special ability ===\n";
	ScavTrap st("Scavy");
	st.attack("an intruder");
	st.guardGate();
	std::cout << "\n=== ScavTrap: copy ctor and assignment ===\n";
	ScavTrap stCopy = st;
	stCopy.attack("copied target");
	ScavTrap stAssign("Temp");
	stAssign = st;
	stAssign.attack("assigned target");
	std::cout << "\n=== Nested scope: show construction/destruction chaining ===\n";
	{
		ClapTrap innerCt("InnerClap");
		ScavTrap innerSt("InnerScav");
		innerCt.attack("local bot");
		innerSt.attack("local intruder");
		innerSt.guardGate();
	}
	std::cout << "\n=== End of tests ===\n";
	return 0;
}