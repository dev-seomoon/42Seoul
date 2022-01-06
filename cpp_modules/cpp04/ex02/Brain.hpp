#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    std::string     getIdea(int index);
    void            setIdea(int index, std::string idea);

    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();
};

#endif