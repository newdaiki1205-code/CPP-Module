/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 11:27:15 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/26 00:08:35 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this == &other)
    return (*this);
  return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input) {
  int type = checkType(input);

  switch (type) {
  case INF:
    toInf(input);
    break;
  case CHAR:
    fromChar(input);
    break;
  case INT:
    fromInt(input);
    break;
  case FLOAT:
    fromFloat(input);
    break;
  case DOUBLE:
    fromDouble(input);
    break;
  default:
    errorMessage();
  }
}

int ScalarConverter::checkType(std::string input) {
  if (input.empty())
    return (ERROR);
  if (checkInf(input))
    return (INF);
  if (checkChar(input))
    return (CHAR);
  return (checkNum(input));
}

bool ScalarConverter::checkInf(std::string input) {
  std::string indexArray[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  int indexNum;

  for (indexNum = 0; indexNum < 6; indexNum++) {
    if (!(input.compare(indexArray[indexNum])))
      break;
  }
  if (indexNum == 6)
    return false;
  return true;
}

int ScalarConverter::checkNum(std::string input) {
  int sign = 0;

  if (!std::isdigit(input[0])) {
    if (input[0] != '-' && input[0] != '+')
      return ERROR;
    if (input.length() == 1)
      return ERROR;
  }
  if (input[0] == '-' || input[0] == '+')
    sign = 1;
  for (unsigned long i = sign; i < input.length(); i++) {
    if (!std::isdigit(input[i]))
      return checkNonInt(input);
  }
  return (INT);
}

int ScalarConverter::checkNonInt(std::string input) {
  const unsigned long point_pos = input.find(".");
  int point_count = 0;
  const unsigned long f_pos = input.find("f");
  int sign = 0;

  if (point_pos == std::string::npos)
    return ERROR;
  if (point_pos == input.length() - 1)
    return ERROR;
  if (!std::isdigit(input[point_pos + 1]))
    return ERROR;
  for (unsigned long i = 0; i < input.length(); i++) {
    if (input[i] == '.')
      point_count++;
  }
  if (point_count != 1)
    return ERROR;
  if (f_pos != std::string::npos && f_pos != input.length() - 1)
    return ERROR;
  if (input[0] == '-' || input[0] == '+')
    sign = 1;
  for (unsigned long i = sign; i < input.length(); i++) {
    if (i == input.length() - 1 && input[i] == 'f')
      break;
    if (i != point_pos && !std::isdigit(input[i]))
      return ERROR;
  }
  if (f_pos != std::string::npos)
    return FLOAT;
  return DOUBLE;
}

void ScalarConverter::fromFloat(std::string input) {
  errno = 0;
  char *p_end = NULL;
  const double value = std::strtod(input.c_str(), &p_end);

  if (p_end == input.c_str()) {
    errorMessage();
    return;
  }
  if (*p_end != 'f') {
    errorMessage();
    return;
  }
  if (errno == ERANGE) {
    errorMessage();
    return;
  }
  if (value >= -std::numeric_limits<float>::max() &&
      value <= std::numeric_limits<float>::max()) {
    toChar(static_cast<float>(value));
    toInt(static_cast<float>(value));
    toFloat(static_cast<float>(value));
    toDouble(static_cast<float>(value));
  } else {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    toDouble(value);
  }
}

void ScalarConverter::fromDouble(std::string input) {
  errno = 0;
  char *p_end = NULL;
  const double value = std::strtod(input.c_str(), &p_end);

  if (p_end == input.c_str()) {
    errorMessage();
    return;
  }
  if (*p_end != '\0') {
    errorMessage();
    return;
  }
  if (errno == ERANGE) {
    errorMessage();
    return;
  }
  toChar((value));
  toInt(value);
  toFloat(value);
  toDouble(value);
}

void ScalarConverter::fromInt(std::string input) {
  errno = 0;
  char *p_end = NULL;
  const long value = std::strtol(input.c_str(), &p_end, 10);

  if (p_end == input.c_str()) {
    errorMessage();
    return;
  }
  if (*p_end != '\0') {
    errorMessage();
    return;
  }
  if (errno == ERANGE) {
    errorMessage();
    return;
  }
  if (value >= std::numeric_limits<int>::min() &&
      value <= std::numeric_limits<int>::max()) {
    toChar(static_cast<int>(value));
    toInt(static_cast<int>(value));
    toFloat(static_cast<int>(value));
    toDouble(static_cast<int>(value));
  } else {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    toFloat(static_cast<double>(value));
    toDouble(static_cast<double>(value));
  }
}

void ScalarConverter::fromChar(std::string input) {
  std::cout << "char: " << input << std::endl;
  std::cout << "int: " << static_cast<int>(input[1]) << std::endl;
  std::cout << "float: " << static_cast<float>(input[1]) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(input[1]) << ".0" << std::endl;
}

void ScalarConverter::toChar(double value) {
  if (0 <= value && value <= 127) {
    char c = static_cast<char>(value);
    if (32 <= c && c <= 126)
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
}

void ScalarConverter::toInt(double value) {
  if (std::numeric_limits<int>::min() <= value &&
      value <= std::numeric_limits<int>::max()) {
    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
  } else {
    std::cout << "int: impossible" << std::endl;
  }
}

void ScalarConverter::toFloat(double value) {
  if (value >= -std::numeric_limits<float>::max() &&
      value <= std::numeric_limits<float>::max()) {
    float f = static_cast<float>(value);
    std::cout << "float: "
              << std::setprecision(std::numeric_limits<float>::digits10) << f;
    std::ostringstream fbuf;
    fbuf << std::setprecision(std::numeric_limits<float>::digits10) << f;
    if (fbuf.str().find(".") == std::string::npos &&
        fbuf.str().find("e") == std::string::npos)
      std::cout << ".0";
    std::cout << "f" << std::endl;
  } else
    std::cout << "float: impossible" << std::endl;
}

void ScalarConverter::toDouble(double value) {
  std::cout << "double: "
            << std::setprecision(std::numeric_limits<double>::digits10)
            << value;
  std::ostringstream dbuf;
  dbuf << std::setprecision(std::numeric_limits<double>::digits10) << value;
  if (dbuf.str().find(".") == std::string::npos &&
      dbuf.str().find("e") == std::string::npos)
    std::cout << ".0";
  std::cout << std::endl;
}

void ScalarConverter::errorMessage() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::toInf(std::string literal) {
  std::string indexArray[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  int indexNum;

  for (indexNum = 0; indexNum < 6; indexNum++) {
    if (!(literal.compare(indexArray[indexNum])))
      break;
  }
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  switch (indexNum % 3) {
  case 0:
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
    break;
  case 1:
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
    break;
  case 2:
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    break;
  }
}

bool ScalarConverter::checkChar(std::string literal) {
  if (literal.length() != 3)
    return (false);
  if (literal[0] != 39 || literal[2] != 39)
    return (false);
  return (true);
}
