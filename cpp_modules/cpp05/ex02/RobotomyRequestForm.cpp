#include "RobotomyRequestForm.hpp"

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  isExecutable(executor);

  srand(time(NULL));
  if ((rand() % 10) >= 5) {
    std::cout << "DRILLING NOISE... <" << getTarget() << "> has been robotomized successfully! 50% of the time!" << std::endl;
  } else {
    std::cout << "Failed to robotomize <" << getTarget() << ">!" << std::endl;
  }
}

RobotomyRequestForm::RobotomyRequestForm(): Form("Blank", 72, 45, "Blank_Robotomy") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form("Blank", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): Form(src) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
  if (this != &src) {
    return (*(new RobotomyRequestForm(src)));
  }
  return (*this);
}
