/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:33:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/07 11:45:08 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <climits>
# include <iostream>
# include <sstream>
# include <string>

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

	static int isCharLiteral(std::string literal);

  public:
	static void convert(std::string literal);
};

#endif
