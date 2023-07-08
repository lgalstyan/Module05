#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(!GetSign())
    {
		throw AForm::SignedSuccessException();
    }

    if (executor.getGrade() > GetExecGrade())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << RED << _target << "has been pardoned by Zaphod Beeblebrox\n" << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm(){}
