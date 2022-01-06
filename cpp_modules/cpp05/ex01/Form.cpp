#include "Form.hpp"

void  Form::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > _gradeToSign)
    throw(GradeTooLowException("grade is too low to sign this form"));
  else
    _isSigned = true;
}

// getters
std::string   Form::getName(void) const
{
  return (_name);
}

unsigned int  Form::getGradeToSign(void) const
{
  return (_gradeToSign);
}

unsigned int  Form::getGradeToExec(void) const
{
  return (_gradeToExec);
}

bool  Form::getIsSigned(void) const
{
  return (_isSigned);
}

// Exception classes

Form::GradeTooHighException::GradeTooHighException(const char* message): _message(message)
{
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char*   Form::GradeTooHighException::what() const throw() {
  return (_message);
}

Form::GradeTooLowException::GradeTooLowException(const char* message): _message(message)
{
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char*   Form::GradeTooLowException::what() const throw() {
  return (_message);
}

// canonical
Form::Form(): _name("Blank"), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec)
: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
  try
  {
    if (_gradeToSign < 1 || _gradeToExec < 1)
      throw(GradeTooHighException("Grade is too high on construction"));
    else if (_gradeToSign > 150 || _gradeToExec > 150)
      throw(GradeTooLowException("Grade is too low on construction"));
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

Form::~Form() {}

Form::Form(const Form& src): _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
  try
  {
    if (_gradeToSign < 1 || _gradeToExec < 1)
      throw(GradeTooHighException("Grade is too high on copy construction"));
    else if (_gradeToSign > 150 || _gradeToExec > 150)
      throw(GradeTooLowException("Grade is too low on copy construction"));
    else
      _isSigned = false;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

Form&   Form::operator=(const Form& src)
{
  if (this != &src)
    return (*(new Form(src)));
  return (*this);
}

std::ostream& operator<<(std::ostream& os, Form& obj)
{
  os << "[Form info] name: " << obj.getName()
    << " | grades : " << obj.getGradeToSign() << " to sign, " << obj.getGradeToExec() << " to execute"
    << " | isSigned : " << obj.getIsSigned();
  return (os);
}