#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _grade(150),  _name("undefine") {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(int grade, const std::string name) :  _name(name)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

const std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::GradeIncr()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        --_grade;
}

void Bureaucrat::GradeDecr()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        ++_grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
        const_cast<std::string&>(_name) = other._name;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
    os <<  bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
    return (os);
}



const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The lowest grade is 150, it connot be lowered any further!\n");
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Highest grade in 1, connot be increased anymore!\n");
}
