#include "../include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap Jenny("Jenny");
	ClapTrap Bob("Bob");
	std::cout << std::endl;
	std::cout << "Test1: Attack, TakeDamage, BeRepaired" << std::endl;
	Jenny.setAD(1);
	Jenny.attack(Bob.getName());
	Bob.takeDamage(Jenny.getAD());
	Bob.setAD(1);
	Bob.attack(Jenny.getName());
	Jenny.takeDamage(Bob.getAD());
	Jenny.beRepaired(1);
	std::cout << std::endl;
	std::cout << "Test2: Lose HP and Cannot Move" << std::endl;
	Bob.setAD(11);
	Bob.attack(Jenny.getName());
	Jenny.takeDamage(Bob.getAD());
	Jenny.attack(Bob.getName());
	Jenny.beRepaired(11);
	std::cout << std::endl;
	std::cout << "Test3: Lose EP and Cannot Move" << std::endl;
	for (int i = 0; i < 9; i++)
		Bob.beRepaired(100);
	std::cout << std::endl;
	return (0);
}
