#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string n, const int sg, const int eg);
        ~Form();
        Form(const Form &other);
        Form& operator=(const Form &other);
        std::string GetName() const;
        int GetSignGrade() const;
        int GetExecGrade() const;
        bool GetSign() const;
        void beSigned(const Bureaucrat&);

    private:
        bool _sign;
        const int _SignGrade;
        const int _ExecGrade;
        const std::string _FormName;
        class GradeTooHighException: public std::exception
        {
            public:
                const char * what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& fix);

#endif