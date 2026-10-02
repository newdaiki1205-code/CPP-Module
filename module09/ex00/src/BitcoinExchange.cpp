/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:32:59 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/30 14:31:47 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  _database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this == &other)
    return *this;
  _database = other._database;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::exchange(const std::string &input) {
  std::string tmp;
  std::ifstream inFile(input.c_str());
  if (!inFile)
    throw FileError();

  mapCreation();
  while (getline(inFile, tmp)) {
    try {
      parse_search(tmp);
    } catch (BadInput &e) {
      std::cout << e.what() << " => " << tmp << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::parse_search(const std::string &_readLine) {
  if (!_readLine.compare("date | value"))
    return;
  size_t pos = _readLine.find("|");
  if (pos == std::string::npos)
    throw BadInput();

  if (!checkKey(_readLine.substr(0, pos), 'i'))
    throw BadInput();

  std::string key = _readLine.substr(0, pos - 1);
  double value = checkValue(_readLine.substr(pos + 1));
  search(key, value);
}

void BitcoinExchange::search(const std::string &_target, const double _value) {
  std::map<std::string, double>::iterator it = _database.lower_bound(_target);
  if (it != _database.end() && !it->first.compare(_target))
    std::cout << _target << " => "
              << std::setprecision(std::numeric_limits<double>::digits10)
              << _value << " = " << (_value * it->second) << std::endl;
  else if (it == _database.begin())
    throw NonExist();
  else
    std::cout << _target << " => "
              << std::setprecision(std::numeric_limits<double>::digits10)
              << _value << " = " << (_value * (--it)->second) << std::endl;
}

double BitcoinExchange::checkValue(const std::string &_subValue) {
  if (!checkValueFormat(_subValue))
    throw BadInput();

  char *endptr = NULL;
  double ret = strtod(_subValue.c_str(), &endptr);
  if (endptr == _subValue.c_str())
    throw BadInput();
  if (*endptr != '\0')
    throw BadInput();
  if (ret < 0)
    throw NegativeValue();
  if (1000 < ret)
    throw TooLeargeValue();
  return ret;
}

bool BitcoinExchange::checkValueFormat(const std::string &_subValue) {
  if (_subValue.empty())
    return (false);

  unsigned int start = 0;
  if (_subValue[start] != ' ')
    return (false);
  start++;

  size_t ppos = _subValue.find(".");
  if (ppos != std::string::npos) {
    if (ppos == _subValue.length() - 1)
      return (false);
    if (_subValue.find(".", ppos + 1) != std::string::npos)
      return (false);
  }
  if (start != _subValue.length() &&
      (_subValue[start] == '+' || _subValue[start] == '-'))
    start++;
  if (start != _subValue.length() && _subValue[start] == '.')
    return (false);

  for (unsigned int i = start; i < _subValue.length(); i++) {
    if (!std::isdigit(_subValue[i])) {
      if (_subValue[i] != '.')
        return (false);
    }
  }
  return (true);
}

bool BitcoinExchange::checkKey(const std::string &_subKey, const char flag) {
  size_t pos1 = _subKey.find("-");
  if (pos1 == std::string::npos || pos1 != 4)
    return (false);
  size_t pos2 = _subKey.find("-", pos1 + 1);
  if (pos2 == std::string::npos || pos2 != 7)
    return (false);
  if (flag == 'i' && _subKey.substr(pos2 + 1).length() != 3)
    return (false);
  else if (flag == 'd' && _subKey.substr(pos2 + 1).length() != 2)
    return (false);
  if (flag == 'i' && _subKey[_subKey.length() - 1] != ' ')
    return (false);

  std::string year = _subKey.substr(0, pos1);
  if (!checkDigit(year))
    return (false);
  std::string month = _subKey.substr(pos1 + 1, 2);
  if (!checkDigit(month))
    return (false);
  if (1 > std::atoi(month.c_str()) || 12 < std::atoi(month.c_str()))
    return (false);
  std::string day = _subKey.substr(pos2 + 1, 2);
  if (!checkDigit(day))
    return (false);
  if (!checkDay(std::atoi(year.c_str()), std::atoi(month.c_str()),
                std::atoi(day.c_str())))
    return (false);

  return (true);
}

bool BitcoinExchange::checkDigit(const std::string &str) {
  for (unsigned int i = 0; i < str.length(); i++) {
    if (!std::isdigit(str[i]))
      return (false);
  }
  return (true);
}

bool BitcoinExchange::checkDay(const int _year, const int _month,
                               const int _day) {
  if (_month == 2 && checkLeapYear(_year)) {
    if (_day < 1 || 29 < _day)
      return (false);
  } else if (_month == 2) {
    if (_day < 1 || 28 < _day)
      return (false);
  } else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
    if (_day < 1 || 30 < _day)
      return (false);
  } else {
    if (_day < 1 || 31 < _day)
      return (false);
  }
  return (true);
}

bool BitcoinExchange::checkLeapYear(const int _year) {
  if (_year % 400 == 0) {
    return true;
  } else if (_year % 100 == 0) {
    return false;
  } else if (_year % 4 == 0) {
    return true;
  } else {
    return false;
  }
}

void BitcoinExchange::mapCreation() {
  std::string tmp;
  std::string key;
  std::string value_str;
  size_t pos;
  double value;
  char *endptr;

  std::ifstream database("data.csv");
  if (!database)
    throw FileError();

  while (getline(database, tmp)) {
    if (tmp.compare("date,exchange_rate")) {
      pos = tmp.find(",");
      if (pos == std::string::npos)
        throw DatabaseError();

      key = tmp.substr(0, pos);
      if (!checkKey(key, 'd'))
        throw DatabaseError();
      value_str = tmp.substr(pos + 1);

      value = strtod(value_str.c_str(), &endptr);
      if (endptr == value_str.c_str())
        throw DatabaseError();
      if (*endptr != '\0')
        throw DatabaseError();

      _database.insert(std::pair<std::string, double>(key, value));
    }
  }
}

const char *BitcoinExchange::BadInput::what() const throw() {
  return "Error: bad input";
}

const char *BitcoinExchange::DatabaseError::what() const throw() {
  return "Error: check your database (no csv format or invalid value)";
}

const char *BitcoinExchange::FileError::what() const throw() {
  return "Error: could not open file.";
}

const char *BitcoinExchange::NegativeValue::what() const throw() {
  return "Error: not a positive number.";
}

const char *BitcoinExchange::TooLeargeValue::what() const throw() {
  return "Error: too large a number.";
}

const char *BitcoinExchange::NonExist::what() const throw() {
  return "Error: data does not exist.";
}
