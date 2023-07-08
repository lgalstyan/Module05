#include "AForm.hpp"

AForm::AForm() : _sign(false), _SignGrade(120), _ExecGrade(150), _FormName("Undefine") {}

AForm::AForm(const std::string n, const int sg, const int eg) : _sign(false), _SignGrade(sg), _ExecGrade(eg), _FormName(n) 
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

AForm::AForm(const AForm &other): _sign(other._sign), _SignGrade(other._SignGrade), _ExecGrade(other._ExecGrade), _FormName(other._FormName) {}

AForm& AForm::operator=(const AForm &other)
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

AForm::~AForm(){}

void AForm::beSigned(Bureaucrat& bur)
{
    if (bur.getGrade() <= _SignGrade)
        _sign = true;
    else    
        _sign = false;
}

std::string AForm::GetName() const
{
    return (_FormName);
}

int AForm::GetSignGrade() const
{
    return (_SignGrade);
}

int AForm::GetExecGrade() const
{
    return (_ExecGrade);
}

bool AForm::GetSign() const
{
    return (_sign);
}
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << BLUE << "Information about form\n" << RESET ;
    os << "Name is: " << form.GetName() << "\n";
    os << "AForm is: ";
    if (form.GetSign())
        os << "Signatured!\n";
    else
        os << "Unsignatured!\n";
    os << "Grade required to sign is: " << form.GetSignGrade() << std::endl;
    os << "Grade required to execute is: " << form.GetExecGrade() << std::endl;
    return (os);
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("The lowest grade is 150, it connot be lowered any further!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Highest grade in 1, connot be increased anymore!");
}

const char* AForm::SignedSuccessException::what() const throw()
{
    return ("The form isn't signed!");
}

const char* AForm::IncorrectFormName::what() const throw()
{
    return ("Form name is incorrect!");
}
