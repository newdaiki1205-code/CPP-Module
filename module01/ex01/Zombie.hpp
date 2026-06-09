/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:08:52 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 17:20:45 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  public:
	Zombie(){};
	Zombie(std::string given);
	~Zombie();
	void announce(void);
	void setName(std::string);

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif