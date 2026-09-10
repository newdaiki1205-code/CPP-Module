/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:01:21 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 14:01:21 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	std::cout << "Test1: The order of constructor" << std::endl;
	ClapTrap Jenny("Jenny");
	ScavTrap Robot("Robot");
	std::cout << std::endl;
	std::cout << "Test2: Differnt attack function" << std::endl;
	Jenny.attack(Robot.getName());
	Robot.takeDamage(Jenny.getAD());
	std::cout << std::endl;
	Robot.attack(Jenny.getName());
	Jenny.takeDamage(Robot.getAD());
	std::cout << std::endl;
	std::cout << "Test3: Unique function in ScavTrap(guardGate)" << std::endl;
	Robot.guardGate();
	std::cout << std::endl;
	std::cout << "Test4: Inherited Function from ClapTrap(beRepaired)" << std::endl;
	Robot.beRepaired(10000);
	std::cout << std::endl;
	std::cout << "Test5: ScavTrap's Copy Constructor and Check the order of construction" << std::endl;
	ScavTrap Bob(Robot);
	Bob.setName("Bob");
	std::cout << "Set Name: Bob" << std::endl;
	std::cout << "[Bob's INFO] HP: " << Bob.getHP() << " EP: " << Bob.getEP() << " AD: " << Bob.getAD() << std::endl;
	std::cout << std::endl;
	std::cout << "Test6: Copy Assignment Operator (ClapTrap = ScavTrap)" << std::endl;
	std::cout << "[Jenny's INFO] HP: " << Jenny.getHP() << " EP: " << Jenny.getEP() << " AD: " << Jenny.getAD() << std::endl;
	Jenny = Bob;
	Jenny.setName("Jenny");
	std::cout << "Copy Bob to Jenny" << std::endl;
	std::cout << "[Jenny's INFO] HP: " << Jenny.getHP() << " EP: " << Jenny.getEP() << " AD: " << Jenny.getAD() << std::endl;
	Jenny.attack(Robot.getName());
	Robot.takeDamage(Bob.getAD());
	std::cout << std::endl;
	return (0);
}
