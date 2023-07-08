#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150),  _name("undefine") {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name, int grade) :  _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) :  _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
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
    try {
        if (_grade == 1)
            throw GradeTooHighException();
        else
            --_grade;
    } catch (const GradeTooHighException& e) {
        e.what();
    }
}

void Bureaucrat::GradeDecr()
{
    try {
        if (_grade == 150)
            throw GradeTooLowException();
        else
            ++_grade;
    } catch (const GradeTooLowException& e) {
        e.what();
    }
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

void Bureaucrat::signForm(AForm& form)
{
    try
    {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.GetName() << std::endl;
	} catch (const std::exception& e)
    {
		std::cout   << _name << " couldn't sign " << form.GetName()
                    << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.GetName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The lowest grade is 150, it connot be lowered any further!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Highest grade in 1, connot be increased anymore!\n");
}
