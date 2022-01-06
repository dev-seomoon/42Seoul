#include "ShrubberyCreationForm.hpp"

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  try
  {
    isExecutable(executor);
    std::cout << getTarget() << "_shrubbery created. " << std::endl;
    std::string filename = getTarget() + "_shrubbery";
    std::string shrubbery = "      .\n   __/ \\__\n   \\     /\n   /.'o'.\\\n    .o.'.\n   .'.'o'.\n  o'.o.'.o.\n .'.o.'.'.o.\n.o.'.o.'.o.'.\n   [_____]\n    \\___/    \n";
    std::ofstream ofs(filename.c_str());
    if (ofs.is_open()) {
      ofs << shrubbery;
      ofs.close();
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    throw(GradeTooLowException(e.what()));
  }
}

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Blank", 145, 137, "Blank_Shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): Form("Blank", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): Form(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&    ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
  if (this != &src) {
    return (*(new ShrubberyCreationForm(src)));
  }
  return (*this);
}
