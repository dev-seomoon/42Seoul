#include "Intern.hpp"

Form*   Intern::makeForm(std::string name, std::string target)
{
  for (int i = 0; i < 3; i++)
  {
    if (forms[i].name == name) {
      std::cout << "Intern creates form " << name << ". " << std::endl;
      return ((this->*(forms[i].func))(target));
    }
  }
  std::cout << "Form " << name << " is not available. " << std::endl;
  return (NULL);
}

Form*   Intern::makeShrubberyCreationForm(std::string target)
{
  return (new ShrubberyCreationForm(target));
}

Form*   Intern::makeRobotomyRequestForm(std::string target)
{
  return (new RobotomyRequestForm(target));
}

Form*   Intern::makePresidentialPardonForm(std::string target)
{
  return (new PresidentialPardonForm(target));
}

Intern::Intern() {
  forms[0].name = "shrubbery creation";
  forms[0].func = &Intern::makeShrubberyCreationForm;
  forms[1].name = "robotomy request";
  forms[1].func = &Intern::makeRobotomyRequestForm;
  forms[2].name = "presidential pardon";
  forms[2].func = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern& src) {
  if (this != &src) {
    forms[0].name = "shrubbery creation";
    forms[0].func = &Intern::makeShrubberyCreationForm;
    forms[1].name = "robotomy request";
    forms[1].func = &Intern::makeRobotomyRequestForm;
    forms[2].name = "presidential pardon";
    forms[2].func = &Intern::makePresidentialPardonForm; 
  }
}

Intern::~Intern() {}

Intern&   Intern::operator=(const Intern& src) {
  if (this != &src) {
    return (*(new Intern()));
  }
  return (*this);
}