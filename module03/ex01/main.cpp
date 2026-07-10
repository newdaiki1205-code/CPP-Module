#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Robot("Robot");
    ClapTrap Jenny("Jenny");

    std::cout << std::endl;

    Jenny.attack(Robot.getName());
    Robot.takeDamage(Jenny.getAD());

    std::cout << std::endl;

    Robot.attack(Jenny.getName());
    Jenny.takeDamage(Robot.getAD());

    std::cout << std::endl;

    Robot.guardGate();

    std::cout << std::endl;

    ScavTrap Bob (Robot);
    Bob.setName("Bob");
    Bob.attack(Robot.getName());
    Robot.takeDamage(Bob.getAD());

    std::cout << std::endl;

    Jenny = Bob;
    Jenny.setName("Jenny");
    Jenny.attack(Robot.getName());
    Robot.takeDamage(Bob.getAD());
    Robot.beRepaired(10000);

    std::cout << std::endl;

    for(int i = 0; i < 5; i++)
    {
        Bob.attack(Jenny.getName());
        Jenny.takeDamage(Bob.getAD());
        std::cout << std::endl;
    }

    Jenny.beRepaired(100);
    
    std::cout << std::endl;

    return 0;
}