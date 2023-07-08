#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
     public:
        AForm();
        AForm(const std::string n, const int sg, const int eg);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        std::string GetName() const;
        int GetSignGrade() const;
        int GetExecGrade() const;
        bool GetSign() const;
        void beSigned(Bureaucrat&);
        virtual void execute(Bureaucrat const & executor) const = 0 ;
        
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
        
        class SignedSuccessException: public std::exception
        {
            public:
                const char * what() const throw();
        };

        class IncorrectFormName: public std::exception
        {
            public:
                const char * what() const throw();
        };

    private:
        bool _sign;
        const int _SignGrade;
        const int _ExecGrade;
        const std::string _FormName;
};

std::ostream& operator<<(std::ostream& os, const AForm& fix);

#endif