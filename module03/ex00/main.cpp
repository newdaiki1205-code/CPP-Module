#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Jenny("Jenny");
    ClapTrap Bob("Bob");

    std::cout << std::endl;

    Jenny.attack("Bob");
    Bob.takeDamage(1);
    Bob.attack("Jenny");
    Jenny.takeDamage(1);
    Jenny.beRepaired(1);

    std::cout << std::endl;

    Jenny.takeDamage(9);
    Jenny.beRepaired(9);

    std::cout << std::endl;

    Jenny.takeDamage(11);
    Jenny.attack("Bob");
    Jenny.beRepaired(11);

    std::cout << std::endl;

    for(int i = 0; i < 12; i++)
        Bob.attack("Jenny");
    
    std::cout << std::endl;

    return 0;
}