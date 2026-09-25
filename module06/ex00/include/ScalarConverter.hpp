/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:33:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/26 00:08:27 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  static int checkType(std::string input);
  static bool checkInf(std::string input);
  static bool checkChar(std::string input);
  static int checkNum(std::string input);
  static int checkNonInt(std::string input);
  static void errorMessage();
  static void fromChar(std::string input);
  static void convertNum(std::string input, int type);
  static void fromInt(std::string input);
  static void fromFloat(std::string input);
  static void fromDouble(std::string input);
  static void toChar(double value);
  static void toInt(double value);
  static void toFloat(double value);
  static void toDouble(double value);
  static void toInf(std::string literal);

public:
  static void convert(std::string literal);
};

enum Type { INF, CHAR, INT, FLOAT, DOUBLE, ERROR };

#endif
