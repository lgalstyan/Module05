#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(int grade, const std::string name);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        const std::string getName() const;
        int getGrade() const;
        void GradeIncr();
        void GradeDecr();
        void signForm(Form& );

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