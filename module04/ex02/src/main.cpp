#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

void check(const A_Animal* animal)
{
    animal->makeSound();
}

int main()
{
    //const A_Animal* meta = new A_Animal();
    const A_Animal* j = new Dog();
    const A_Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();

    std::cout << std::endl;

    check(j);
    check(i);

    std::cout << std::endl;

    delete j;
    delete i;
    //delete meta;

    std::cout << std::endl;

    const A_Animal* base[2];
    for(int i = 0; i < 1 ; i++)
        base[i] = new Dog();
    std::cout << std::endl;
    for(int i = 1; i < 2 ; i++)
        base[i] = new Cat();
    std::cout << std::endl;
    for(int i = 0; i < 2 ; i++)
        delete base[i];

    return 0;
}