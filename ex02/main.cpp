#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {    
        Bureaucrat buro("John", 2);
        
        ShrubberyCreationForm shrubbery("Garden");

        RobotomyRequestForm robot("Auto");
        PresidentialPardonForm president("Naxagah");

        buro.signForm(shrubbery);

        shrubbery.beSigned(buro);
        robot.beSigned(buro);
        president.beSigned(buro);

        buro.executeForm(shrubbery);
        buro.executeForm(robot);
        buro.executeForm(president);
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
