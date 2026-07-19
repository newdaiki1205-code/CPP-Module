#ifndef CHARACTER_HPP 
# define CHARACTER_HPP 

#include "ICharacter.hpp"


class Character: public ICharacter
{
    private:
      AMateria *inventry[4];
      std::string name;

    public:
        Character(std::string name);
        ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        std::string const & getName() const override;
        void equip(AMateria* m) override;
        void unequip(int idx) override;
        void use(int idx, Character& target) override;
};

#endif // !CHARACTER_HPP
                             //
