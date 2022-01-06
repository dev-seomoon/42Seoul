#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* materias[4];

public:
    virtual void    learnMateria(AMateria* materia);
    virtual AMateria*   createMateria(std::string const & type);

    MateriaSource();
    MateriaSource(const MateriaSource& source);
    virtual ~MateriaSource();
    MateriaSource&  operator=(const MateriaSource& source);
};

#endif