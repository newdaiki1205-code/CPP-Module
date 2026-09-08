#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int main()
{
  const A_Animal* dog = new Dog();
  const A_Animal* cat = new Cat();

  std::cout << std::endl;

  std::cout << dog->getType() << std::endl;
  dog->makeSound();

  std::cout << std::endl;
  
  std::cout << cat->getType() << std::endl;
  cat->makeSound();

  std::cout << std::endl;

  delete dog;
  delete cat;

  return 0;

}

