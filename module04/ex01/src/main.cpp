#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int main()
{
  std::cout << "Test1: Simplest Array (1 Dog and 1 Cat)" << std::endl;
  const Animal* base[2];
  for(int i = 0; i < 1 ; i++)
    base[i] = new Dog();
  std::cout << std::endl;
  for(int i = 1; i < 2 ; i++)
    base[i] = new Cat();
  std::cout << std::endl;
  for(int i = 0; i < 2 ; i++)
    delete base[i];

  std::cout << std::endl;
  std::cout << "Test2: Large Array (10 Dog and 10 Cat)" << std::endl;
  const Animal* test[20];
  for(int i = 0; i < 10; i++)
  {
    std::cout << "loop " << i << std::endl;
    test[i] = new Dog();
  }
  std::cout << std::endl;
  for(int i = 10; i < 20; i++)
  {
    std::cout << "loop " << i << std::endl;
    test[i] = new Cat();
  }
  std::cout << std::endl;
  for(int i = 0; i < 20; i++)
  {
    std::cout << "loop " << i << std::endl;
    delete test[i];
  }

  std::cout << std::endl;
  std::cout << "Test3: Deep Copy check" << std::endl;
  Dog* originalDog = new Dog();
  originalDog->setIdea("this is original dog");
  std::cout << originalDog->getIdea() << std::endl;
  std::cout << std::endl;
  Dog* copyDog = new Dog(*originalDog);
  std::cout << copyDog->getIdea() << std::endl;
  std::cout << std::endl;
  Dog* assignDog = new Dog();
  assignDog->setIdea("this is new dog");
  std::cout << assignDog->getIdea() << std::endl;

  *assignDog = *originalDog;
  std::cout << assignDog->getIdea() << std::endl;

  std::cout << std::endl;

  delete originalDog;
  delete copyDog;
  delete assignDog;

  std::cout << std::endl;

  Cat* originalCat = new Cat();
  originalCat->setIdea("this is original cat");
  std::cout << originalCat->getIdea() << std::endl;
  std::cout << std::endl;
  Cat* copyCat = new Cat(*originalCat);
  std::cout << copyCat->getIdea() << std::endl;
  std::cout << std::endl;
  Cat* assignCat = new Cat();
  assignCat->setIdea("this is new cat");
  std::cout << assignCat->getIdea() << std::endl;

  *assignCat = *originalCat;
  std::cout << assignCat->getIdea() << std::endl;

  std::cout << std::endl;

  delete originalCat;
  delete copyCat;
  delete assignCat;

  return 0;
}
