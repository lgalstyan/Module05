#include "Intern.hpp"

Intern::Intern(){}

Intern& Intern::operator=(const Intern& other)
{
    if (this == &other) {
        return *this;
    }
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm* form = NULL;
    int i = 0;

    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    while (i < 3 && formName != arr[i])
        ++i;
    switch (i)
    {
        case 0:
            form = createShrubberyCreationForm(target);
            break;
        case 1:
            form = createRobotomyRequestForm(target);
            break;
        case 2:
            form = createPresidentialPardonForm(target);
            break;
        default:
            throw AForm::IncorrectFormName();
            break;
    }
    return form;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::~Intern() {}
