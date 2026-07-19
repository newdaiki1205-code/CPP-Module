#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:


    public:
        Ice(std::string const & type);
        ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);

        AMateria* clone() const override;
        void use(ICharacter& target) override;

};

#endif