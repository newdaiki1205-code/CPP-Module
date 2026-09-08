#include "../include/ClapTrap.hpp"
#include "../include/DiamondTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test1: The order of Construction and check attributes." << std::endl;
	DiamondTrap Robot("Robot");
	std::cout << std::endl;
	std::cout << "Test2: attack function inheritted from ScavTrap" << std::endl;
	Robot.attack("None");
	std::cout << std::endl;
	std::cout << "Test3: Unique function in DiamondTrap(whoAmI)" << std::endl;
	Robot.whoAmI();
	std::cout << std::endl;
	std::cout << "Test4: other inherited functions from the base" << std::endl;
	Robot.takeDamage(30);
	Robot.beRepaired(30);
	Robot.guardGate();
	Robot.highFivesGuys();
	Robot.showStatus();
	std::cout << std::endl;
}
