/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:42:10 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/07 12:06:56 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string literal)
{
	toChar(literal);
	toInt(literal);
	//  toFloat(literal);
	//  toDouble(literal);
}

void ScalarConverter::toChar(std::string literal)
{
	long long	num;

	if (isCharLiteral(literal))
		return ;
	std::istringstream isVar(literal);
	isVar >> num;
	if (std::isprint(num))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;
}

int ScalarConverter::isCharLiteral(std::string literal)
{
	if (literal.length() != 3)
		return (0);
	if (literal[0] != 39 || literal[2] != 39)
		return (0);
	std::cout << "char: " << literal[1] << std::endl;
	return (1);
}

void ScalarConverter::toInt(std::string literal)
{
	long long	num;

	std::istringstream isVar(literal);
	isVar >> num;
	if (literal != "0" && num == 0)
		std::cout << "int: Impossible" << std::endl;
	else if (num > INT_MIN && num < INT_MAX)
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
}
