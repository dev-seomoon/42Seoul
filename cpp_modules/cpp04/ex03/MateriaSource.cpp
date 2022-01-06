#include "MateriaSource.hpp"

void        MateriaSource::learnMateria(AMateria* materia)
{
    if (materia == NULL) return;
    for (int i = 0; i < 4; i++) {
        if (materias[i] == NULL) {
            materias[i] = materia->clone();
            delete materia;
            return;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (materias[i] != NULL) 
        {
            if (materias[i]->getType() == type)
                return (materias[i]->clone());
        }
    }
    return NULL;
}

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called. " << std::endl;
    for (int i = 0; i < 4; i++) {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
    std::cout << "MateriaSource copy constructor called. " << std::endl;
    *this = ms;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called. " << std::endl;
    for (int i = 0; i < 4; i++) {
        if (materias[i] != NULL) {
            delete materias[i];
        }
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& ms)
{
    if (this != &ms) {
        for (int i = 0; i < 4; i++)
            delete materias[i];
        for (int i = 0; i < 4; i++) {
            if (ms.materias[i] != NULL)
            materias[i] = ms.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return (*this);
}