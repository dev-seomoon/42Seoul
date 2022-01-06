#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
  public:
    virtual void  execute(Bureaucrat const & executor) const;

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string&target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
};

#endif