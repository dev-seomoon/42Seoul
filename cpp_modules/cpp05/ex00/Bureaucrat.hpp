#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>

class Bureaucrat
{
  private:
    const std::string _name;
    unsigned int      _grade;

  public:
    const std::string getName(void) const;
    unsigned int      getGrade(void) const;

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
        ~GradeTooLowException() throw(); //virtual
        const char*   what() const throw(); //virtual
    };

    void              increaseGrade(void);
    void              decreaseGrade(void);

    Bureaucrat(); // not use
    Bureaucrat(const std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& src);
    ~Bureaucrat();
    Bureaucrat&       operator=(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

#endif