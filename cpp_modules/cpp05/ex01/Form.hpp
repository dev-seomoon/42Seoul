#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
  private:
    const std::string   _name;
    const unsigned int  _gradeToSign;
    const unsigned int  _gradeToExec;
    bool                _isSigned;

  public:
    std::string   getName(void) const;
    unsigned int  getGradeToSign(void) const;
    unsigned int  getGradeToExec(void) const;
    bool                getIsSigned(void) const;

    class GradeTooHighException : public std::exception {
      private:
        const char*   _message;
      public:
        GradeTooHighException(const char* message);
        ~GradeTooHighException() throw();
        const char*     what() const throw();
    };

    class GradeTooLowException : public std::exception {
      private:
        const char*   _message;
      public:
        GradeTooLowException(const char* message);
        ~GradeTooLowException() throw();
        const char*   what() const throw();
    };

    void  beSigned(const Bureaucrat& bureaucrat);

    Form();
    Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec);
    Form(const Form& src);
    Form& operator=(const Form& src);
    ~Form();
};

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif