#include "../include/AMateria.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
  std::cout << "Test1: Test in the subject" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  std::cout << std::endl;
  src->learnMateria(new Cure());
  std::cout << std::endl;

  ICharacter* me = new Character("me");
  std::cout << std::endl;
  AMateria* tmp;
  tmp = src->createMateria("ice");
  std::cout << std::endl;
  me->equip(tmp);
  std::cout << std::endl;
  tmp = src->createMateria("cure");
  std::cout << std::endl;
  me->equip(tmp);
  std::cout << std::endl;

  ICharacter* bob = new Character("bob");
  std::cout << std::endl;
  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << std::endl;

  delete bob;
  std::cout << std::endl;
  delete me;
  std::cout << std::endl;
  delete src;
  std::cout << std::endl;

  std::cout << "------------------------------------------------------------------------------" << std::endl;

  std::cout << "Tese2: Learn more than 4 materia" << std::endl;
  IMateriaSource* src2 = new MateriaSource();
  for(int i = 0; i <= 4; i++)
  {
    if(i == 4)
      std::cout << "Now inventry of IMateriaSource is full with 4 materia" << std::endl;
    src2->learnMateria(new Ice());
    std::cout << std::endl;
  }
  delete src2;
  std::cout << std::endl;
  
  std::cout << "------------------------------------------------------------------------------" << std::endl;

  std::cout << "Tese3: Equip more than 4 materia" << std::endl;
  IMateriaSource* src3 = new MateriaSource();
  src3->learnMateria(new Ice());
  std::cout << std::endl;

  ICharacter* test = new Character("me");
  std::cout << std::endl;
  AMateria* tmp2;
  for(int i = 0; i <= 4; i++)
  {
    if(i == 4)
      std::cout << "Now inventry of Character is full with 4 materia" << std::endl;
    tmp2 = src3->createMateria("ice");
    test->equip(tmp2);
    std::cout << std::endl;
  }
  delete test;
  std::cout << std::endl;
  delete src3;
  std::cout << std::endl;
  
  std::cout << "------------------------------------------------------------------------------" << std::endl;

  std::cout << "Test4: createMateria with unknown type" << std::endl;
  IMateriaSource* src4 = new MateriaSource();
  std::cout << std::endl;
  src4->learnMateria(new Ice());
  std::cout << std::endl;
  AMateria *tmp3;
  tmp3 = src4->createMateria("unknown");
  std::cout << std::endl;
  delete src4;

  return 0;
}
