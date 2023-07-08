#ifndef PEREIDENIALPARDONFORM_HPP
#define PEREIDENIALPARDONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

#endif