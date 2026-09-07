/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:03:17 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/07 10:07:13 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!av[1])
		return (1);
	ScalarConverter::convert(av[1]);
	return (0);
}
