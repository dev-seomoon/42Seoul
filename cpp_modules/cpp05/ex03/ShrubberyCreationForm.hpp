#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
  public:
    virtual void  execute(Bureaucrat const & executor) const;

    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& src);
};

#endif