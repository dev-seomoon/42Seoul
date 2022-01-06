#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain   *brain;

public:
    void    makeSound(void) const;
    Brain   *getBrain(void) const;

    Cat();
    Cat(const Cat& cat);
    Cat&    operator=(const Cat& cat);
    ~Cat();
};

#endif