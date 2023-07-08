#include "Form.hpp"

Form::Form() : _sign(false), _SignGrade(120), _ExecGrade(150), _FormName("Undefine") {}

Form::Form(const std::string n, const int sg, const int eg) : _sign(false), _SignGrade(sg), _ExecGrade(eg), _FormName(n) 
{
    if(sg < 1 || eg < 1)
    {
        throw GradeTooLowException();
    }
    else if (sg > 150 || eg > 150)
    {
        throw GradeTooHighException();
    }
}

Form::Form(const Form &other): _sign(other._sign), _SignGrade(other._SignGrade), _ExecGrade(other._ExecGrade), _FormName(other._FormName) {}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _sign = other._sign;
        const_cast<int&>(_SignGrade) = other._SignGrade;
        const_cast<int&>(_ExecGrade) = other._ExecGrade;
        const_cast<std::string&>(_FormName) = other._FormName;
    }
    return (*this);
}

Form::~Form(){}

void Form::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() <= _SignGrade)
        _sign = true;
    else
        throw GradeTooLowException();
}

std::string Form::GetName() const
{
    return (_FormName);
}

int Form::GetSignGrade() const
{
    return (_SignGrade);
}

int Form::GetExecGrade() const
{
    return (_ExecGrade);
}

bool Form::GetSign() const
{
    return (_sign);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << BLUE << "Information about form\n" << RESET ;
    os << "Name is: " << form.GetName() << "\n";
    os << "Form is: ";
    if (form.GetSign())
        os << "Signatured!\n";
    else
        os << "Unsignatured!\n";
    os << "Grade required to sign is: " << form.GetSignGrade() << std::endl;
    os << "Grade required to execute is: " << form.GetExecGrade() << std::endl;
    return (os);
}


const char* Form::GradeTooLowException::what() const throw()
{
    return ("The lowest grade is 150, it connot be lowered any further!\n");
}


const char* Form::GradeTooHighException::what() const throw()
{
    return ("Highest grade in 1, connot be increased anymore!\n");
}
