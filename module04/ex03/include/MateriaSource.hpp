#ifndef MateriaSource_HPP 
# define MateriaSource_HPP 
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {

    private:
        AMateria *stock[4];

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
       
        void learnMateria(AMateria*) override;
        AMateria* createMateria(std::string const & type) override; 
}

#endif
