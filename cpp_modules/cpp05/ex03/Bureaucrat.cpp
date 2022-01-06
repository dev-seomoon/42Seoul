#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string Bureaucrat::getName(void) const
{
  return (_name);
}

unsigned int  Bureaucrat::getGrade(void) const
{
  return (_grade);
}

void  Bureaucrat::increaseGrade(void)
{
  try {
    if ((_grade - 1) < 1) 
      throw GradeTooHighException("Grade is too high to increase");
    else
      _grade -= 1;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void  Bureaucrat::decreaseGrade(void)
{
  try {
    if ((_grade + 1) > 150)
      throw GradeTooLowException("Grade is too low to decrease");
    else
      _grade += 1;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void  Bureaucrat::signForm(Form& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << "<" << _name << "> signes form" << std::endl;
  } catch (std::exception &e) {
    std::cout << "<" << _name << "> cannot sign form because " << e.what() << std::endl;
  }
}

void  Bureaucrat::executeForm(Form const & form)
{
  try
  {
    form.execute(*this);
    std::cout << "<" << _name << "> executes form" << std::endl;
  } catch (std::exception &e) {
    std::cout << "<" << _name << "> cannot execute form because " << e.what() << std::endl;
  }
}

Bureaucrat::Bureaucrat() { } // not use

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name)
{
  try {
    if (grade < 1)
      throw GradeTooHighException("grade is too high on construction");
    else if (grade > 150)
      throw GradeTooLowException("grade is too low on construction");
    else
      _grade = grade;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    _grade = 150;
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src.getName())
{
  _grade = src.getGrade();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
  if (this != &src) {
    Bureaucrat  *newborn = new Bureaucrat(src);
    return (*newborn);
  }
  return (*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
  os << "<" << obj.getName() << ">, bureaucrat grade <" << obj.getGrade() << ">";
  return (os);
}

// Exception

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* message)
: _message(message) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {};

const char*   Bureaucrat::GradeTooHighException::what() const throw()
{
  return (_message);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* message)
: _message(message) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return (_message);
}
