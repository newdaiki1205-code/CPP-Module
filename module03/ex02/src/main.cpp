#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test1: The order of construction" << std::endl;
	FragTrap Tom("Tom");
	std::cout << std::endl;
	std::cout << "Test2: Unique Function in FragTrap(highFivesGuys)" << std::endl;
	Tom.highFivesGuys();
	std::cout << std::endl;
	std::cout << "Test3: Inherited Function from ClapTrap" << std::endl;
	Tom.attack("None");
	std::cout << std::endl;
	return (0);
}
