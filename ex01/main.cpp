#include "Form.hpp"

int main()
{ 
    try
    {
        Bureaucrat v(12, "Bureaucrat");

        Form a; 
        a.beSigned(v);
        std::cout << a << std::endl;
    
        Form b("Zina", 140, 10);
        b.beSigned(v);
        std::cout << b;
    } 
    catch (std::exception &a)
    {
        std::cout << a.what();
    }
    return (0);
}