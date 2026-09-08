/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:44:56 by dshirais          #+#    #+#             */
/*   Updated: 2026/07/14 08:56:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_Animal_HPP
# define A_Animal_HPP

#include <iostream>

class A_Animal
{
    protected:
        std::string type;

    public:
        A_Animal();
        A_Animal(const A_Animal& other);
        A_Animal& operator=(const A_Animal& other);
        virtual ~A_Animal();

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif
