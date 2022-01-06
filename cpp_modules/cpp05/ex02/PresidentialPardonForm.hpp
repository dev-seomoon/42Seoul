#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
  public:
    virtual void  execute(Bureaucrat const & executor) const;

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm&   operator=(const PresidentialPardonForm& src);
};

#endif