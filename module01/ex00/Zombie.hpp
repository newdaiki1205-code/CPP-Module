/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:08:52 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 16:24:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  public:
	Zombie(std::string given);
	~Zombie();
	void announce(void);

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif