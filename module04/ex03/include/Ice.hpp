/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:51:15 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 14:51:15 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    ~Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);

    AMateria* clone() const ;
    void use(ICharacter& target) ;

};

#endif

