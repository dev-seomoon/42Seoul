#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

#include "ICharacter.hpp"

// Item
class AMateria
{
protected:
	std::string	type;

public:
	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria& materia);
	virtual ~AMateria();
	AMateria&	operator=(const AMateria& materia);

	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0; // 순수 가상 함수 (자식 클래스에서 구현)
	virtual void use(ICharacter& target);
};

#endif