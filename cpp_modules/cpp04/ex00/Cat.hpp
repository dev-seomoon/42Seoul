#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
    void    makeSound(void) const;

    Cat();
    Cat(const Cat& cat);
    Cat&    operator=(const Cat& cat);
    ~Cat();
};

#endif