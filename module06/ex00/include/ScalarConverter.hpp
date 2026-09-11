/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:33:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/11 14:14:40 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <limits>
# include <iostream>
# include <sstream>
# include <string>
# include <float.h>
# include <cmath>
# include <iomanip>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	ScalarConverter &operator=(ScalarConverter &other);
	~ScalarConverter();

	static void toChar(std::string literal);
	static void toInt(std::string literal);
	static void toFloat(std::string literal);
	static void toDouble(std::string literal);

	static bool isCharLiteral(std::string literal);
  static bool toInf(std::string literal);

  public:
	static void convert(std::string literal);
};

#endif

