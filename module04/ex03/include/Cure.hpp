/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:02:58 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/09 15:02:58 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    ~Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);

    AMateria* clone() const;
    void use(ICharacter& target);

};

#endif

