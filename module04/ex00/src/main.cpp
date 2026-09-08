#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    delete j;
    delete i;
    delete meta;

    std::cout << std::endl;

    const WrongAnimal* fmeta =new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << std::endl;

    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    fmeta->makeSound();

    std::cout << std::endl;

    delete k;
    delete fmeta;

    return 0;
}

