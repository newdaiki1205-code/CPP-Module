#ifndef CHARACTER_HPP 
# define CHARACTER_HPP 

#include "ICharacter.hpp"


class Character: public ICharacter
{
  private:
    AMateria **inventry;
    std::string name;

  public:
    Character(std::string name);
    ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif // !CHARACTER_HPP
       //
