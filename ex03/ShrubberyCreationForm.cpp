#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 72, 45)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!GetSign())
    {
		throw AForm::SignedSuccessException();
    }

    if (executor.getGrade() > GetExecGrade())
    {
        throw AForm::GradeTooLowException();
    }

    std::string filename = _target + "_shrubbery";
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile <<  "        __ _.--..--._ _               "<< std::endl
                <<    "    .-' _/   _/\\_   \\_'-.         "<< std::endl
                <<    "    |__ /   _/\\__/\\_   \\__|      "<< std::endl
                <<    "       |___/\\_\\__/  \\___|        "<< std::endl
                <<    "              \\__/                 "<< std::endl
                <<    "              \\__/                 "<< std::endl
                <<    "               \\__/                "<< std::endl
                <<    "                \\__/               "<< std::endl
                <<    "             ____\\__/___           "<< std::endl
                <<    "         .- '            ' -.       "<< std::endl
                <<    "~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~ ~~~~  "<< std::endl
                <<    "  ~~~   ~~~~~   ~~~~   ~~~ ~~~      "<< std::endl;
        outFile.close();
    } else {
        throw std::runtime_error("Unable to create file: " + filename);
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}
