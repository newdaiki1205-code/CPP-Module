/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:08:30 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/10 16:08:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP 
# define MateriaSource_HPP 

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {

  private:
    AMateria **stock;
    AMateria *trash_can[100];

  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

    // MateriaSource(const AMateria materia);
    void learnMateria(AMateria*) ;
    AMateria* createMateria(std::string const & type) ; 
};

#endif
