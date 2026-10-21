#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> _database;
  void mapCreation();
  void parse_search(const std::string &_readLine);

  bool checkKey(const std::string &_subKey, const char flag);
  double checkValue(const std::string &_subValue);
  void search(const std::string &_target, const double _value);

  bool checkDigit(const std::string &str);
  bool checkDay(const int _year, const int _month, const int _day);
  bool checkLeapYear(const int _year);
  bool checkValueFormat(const std::string &_subValue);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void exchange(const std::string &input);

  class FileError : public std::exception {
    virtual const char *what() const throw();
  };

  class DatabaseError : public std::exception {
    virtual const char *what() const throw();
  };

  class BadInput : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class NegativeValue : public std::exception {
    virtual const char *what() const throw();
  };

  class TooLeargeValue : public std::exception {
    virtual const char *what() const throw();
  };

  class NonExist : public std::exception {
    virtual const char *what() const throw();
  };
};

#endif // !BITCOINEXCHANGE_HPP
