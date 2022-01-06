#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
  public:
    typedef struct  s_form
    {
      std::string name;
      Form*   (Intern::*func)(std::string);
    }               t_form;
    t_form forms[3];

    Form*   makeForm(std::string name, std::string target);

    Form*   makeShrubberyCreationForm(std::string target);
    Form*   makeRobotomyRequestForm(std::string target);
    Form*   makePresidentialPardonForm(std::string target);

    Intern();
    Intern(const Intern& src);
    ~Intern();
    Intern&   operator=(const Intern& src);
};

#endif