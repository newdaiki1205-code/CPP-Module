/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:42:10 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/07 17:58:32 by dshirais         ###   ########.fr       */
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
  if(toInf(literal))
    return;
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

bool ScalarConverter::toInf(std::string literal)
{
  std::string indexArray[6] ={"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  int indexNum;

  for(indexNum = 0; indexNum < 6; indexNum++)
  {
    if(!(literal.compare(indexArray[indexNum])))
      break;
  }
  if(indexNum == 6)
    return false; 
  std::cout << "char: Impossible" << std::endl;
  std::cout << "int: Impossible" << std::endl;
  switch(indexNum % 3){
    case 0:
      std::cout << "float: -inff" << std::endl;
      std::cout << "float: -inf" << std::endl;
      break;
    case 1:
      std::cout << "float: +inff" << std::endl;
      std::cout << "float: +inf" << std::endl;
      break;
    case 2:
      std::cout << "float: nanf" << std::endl;
      std::cout << "float: nan" << std::endl;
      break;
  }
  return true;
}

void ScalarConverter::toChar(std::string literal)
{
	long double	num;

	if (isCharLiteral(literal))
		return ;
	std::istringstream isVar(literal);
	isVar >> num;
  if(isVar.fail())
    std::cout << "char: Impossible" << std::endl;
  else if (std::isprint(num))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else
		std::cout << "char: Non displayable." << std::endl;
}

bool ScalarConverter::isCharLiteral(std::string literal)
{
	if (literal.length() != 3)
		return (false);
	if (literal[0] != 39 || literal[2] != 39)
		return (false);
	std::cout << "char: " << literal[1] << std::endl;
	return (true);
}

void ScalarConverter::toInt(std::string literal)
{
	long double	num;

	std::istringstream isVar(literal);
	isVar >> num;
  if(isVar.fail())
    std::cout << "int: Impossible" << std::endl;
	else if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max() )
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
}

void ScalarConverter::toFloat(std::string literal)
{
  long double num;

  std::istringstream isVar(literal);
  isVar >> num;
  if(isVar.fail())
    return (void) (std::cout << "float: Impossible" << std::endl);
  else if(num >= -std::numeric_limits<float>::max()  && num <= std::numeric_limits<float>::max() )
  {
    std::cout << "float: " << std::setprecision(10) << static_cast<float>(num);
    if(std::isfinite(static_cast<float>(num)) && num == round(static_cast<float>(num)))
      std::cout << ".0";
    std::cout << "f" << std::endl;
  }
  else
    std::cout << "float: Impossible" << std::endl;
}

void ScalarConverter::toDouble(std::string literal)
{
  long double num;

  std::istringstream isVar(literal);
  isVar >> num;
  if(isVar.fail())
    return (void) (std::cout << "double: Impossible" << std::endl);
  else if(num >= -std::numeric_limits<double>::max()  && num <= std::numeric_limits<double>::max() )
  {
    std::cout << "double: " << std::setprecision(10) << static_cast<double>(num);
    if(std::isfinite(static_cast<double>(num)) && num == round(static_cast<double>(num)))
      std::cout << ".0";
    std::cout << std::endl;
  }
  else
    std::cout << "double: Impossible" << std::endl;
}

