#include "PresidentialPardonForm.hpp"

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  isExecutable(executor);

  std::cout << "<" << getTarget() << "> has been pardoned by Zafod Beeblebrox. " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): Form("Blank", 25, 5, "Blank_Presidential") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): Form("Blank", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&   PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
  if (this != &src) {
    return (*(new PresidentialPardonForm(src)));
  }
  return (*this);
}
