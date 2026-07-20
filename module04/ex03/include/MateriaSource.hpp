#ifndef MateriaSource_HPP 
# define MateriaSource_HPP 

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {

    private:
        AMateria **stock;

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
       
        MateriaSource(const AMateria materia);
        void learnMateria(AMateria*) ;
        AMateria* createMateria(std::string const & type) ; 
};

#endif
