#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat buro("Bureaucrat", 20);
        AForm* fo;
    
        fo = intern.makeForm("shrubbery creation", "Hayat");
        buro.signForm(*fo);
        buro.executeForm(*fo);   
        delete fo;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Intern intern;
        Bureaucrat buro("Bureaucrat", 120);
        AForm* fo;
    
        fo = intern.makeForm("robotomy request", "MrRobot");
        buro.signForm(*fo);
        buro.executeForm(*fo);   
        delete fo;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Intern intern;
        Bureaucrat buro("Bureaucrat", 2);
        AForm* fo;
    
        fo = intern.makeForm("presidential pardon", "Target");
        buro.signForm(*fo);
        buro.executeForm(*fo);   
        delete fo;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Intern intern;
        Bureaucrat buro("Bureaucrat", 20);
        AForm* fo;
    
        fo = intern.makeForm("incorrect", "false");
        buro.signForm(*fo);
        buro.executeForm(*fo);
        delete fo;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}