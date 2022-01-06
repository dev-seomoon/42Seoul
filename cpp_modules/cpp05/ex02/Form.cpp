#include "Form.hpp"

void  Form::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > _gradeToSign)
    throw(GradeTooLowException("grade is too low"));
  else
    _isSigned = true;
}

void    Form::isExecutable(Bureaucrat const & executor) const
{
  if (!this->getIsSigned())
    throw(FormNotSignedException("Sign form before execute"));
  else if (executor.getGrade() > this->getGradeToExec())
    throw(GradeTooLowException("Grade is too low to execute form"));
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

std::string   Form::getTarget(void) const
{
  return (_target);
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

Form::FormNotSignedException::FormNotSignedException(const char* message): _message(message) {}

Form::FormNotSignedException::~FormNotSignedException() throw() {}

const char*   Form::FormNotSignedException::what() const throw() {
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

Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec, const std::string target)
: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false), _target(target)
{
  try
  {
    if (_gradeToSign < 1 || _gradeToExec < 1)
      throw(GradeTooHighException("Grade is too high on construction"));
    else if (_gradeToSign > 150 || gradeToExec > 150)
      throw(GradeTooLowException("Grade is too low on construction"));
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

Form::~Form() {}

Form::Form(const Form& src)
: _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
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
  (void)src;
  return (*this);
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
  os << "[Form info] name: " << form.getName()
    << " | grades : " << form.getGradeToSign() << " to sign, " << form.getGradeToExec() << " to execute"
    << " | isSigned : " << form.getIsSigned()
    << " | target: " << form.getTarget();
  return (os);
}