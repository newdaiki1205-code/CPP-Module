#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:


    public:
        Cure(std::string const & type);
        ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);

        AMateria* clone() const override;
        void use(ICharacter& target) override;

};

#endif