#ifndef ROBOTOMYREQYESTFORM_HPP
#define ROBOTOMYREQYESTFORM_HPP
#include "AForm.hpp"
#include <cstdlib>
#include <fstream>
#include <ctime>
class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

#endif