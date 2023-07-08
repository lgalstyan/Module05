#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const std::string n, const int sg, const int eg);
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string&, const std::string&);

    private:
        AForm* createShrubberyCreationForm(const std::string& target);
        AForm* createRobotomyRequestForm(const std::string& target);
        AForm* createPresidentialPardonForm(const std::string& target);

        // const char* AForm::IncorrectFormName::what() const throw()
        // {
        //     return ("Form name is incorrect!");
        // }
};

#endif