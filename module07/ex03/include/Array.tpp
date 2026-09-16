#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
  std::cout << "Default Constructor called" << std::endl;
  this->_array = new T[0];
  this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
  std::cout << "Array's Constructor with parameter called" << std::endl;
  this->_array = new T[n];
  this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
  std::cout << "Copy Constructor called" <<std::endl;
  this->_array = new T[other._size];
  for(unsigned int i = 0; i < other._size; i++)
    this->_array[i] = other._array[i];
  this->_size = other._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
  std::cout << "Copy Assignment operator called" << std::endl;
  if(this == &other)
    return *this;
  delete[] this->_array;
  this->_array = new T[other._size];
  for(unsigned int i = 0; i < other._size; i++)
    this->_array[i] = other._array[i];
  this->_size = other._size;
  return *this;
}

template <typename T>
Array<T>::~Array()
{
  std::cout << "Destructor called" << std::endl;
  if(this->_array)
    delete[] this->_array;
}

template <typename T>
unsigned int Array<T>::size() const
{
  return this->_size; 
}

template <typename T>
void Array<T>::set(T value, unsigned int i)
{
  if(i >= this->_size)
    throw InvalidAccess();
  this->_array[i] = value;
}

template <typename T>
T Array<T>::get(unsigned int i)
{
  if(i >= this->_size)
    throw InvalidAccess();
  return this->_array[i];
}

