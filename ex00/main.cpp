#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat buroc(150, "Bob");
        std::cout << buroc;
        buroc.GradeDecr();
        std::cout << buroc;

        Bureaucrat burocrat2(15, "Jone");
        std::cout << burocrat2;
        burocrat2.GradeIncr();
    }
    catch(std::exception &a)
    {
        std::cout << RED << a.what() << RESET;
    }

    return (0);
}