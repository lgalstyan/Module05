#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(int , const std::string );
        Bureaucrat(const std::string, int );
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        const std::string getName() const;
        int getGrade() const;
        void GradeIncr();
        void GradeDecr();
        void signForm(AForm& );
        void executeForm(AForm const & form);

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

    private:
        int _grade;
        const std::string _name;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& fix);

#endif