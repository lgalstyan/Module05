#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Roboto", 145, 137)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!GetSign())
    {
		throw AForm::SignedSuccessException();
    }

    if (executor.getGrade() > GetExecGrade())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << RED << "Robotomy drilling noises..." << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << "Robotomization of " << _target << " succeeded!" << std::endl;
    } else {
        std::cout << "Robotomization of " << _target << " failed." << std::endl;
    }
    std::cout << RESET;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
