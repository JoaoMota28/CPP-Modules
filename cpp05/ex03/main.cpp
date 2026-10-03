#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern slave;

    AForm* shrubbery = slave.makeForm("shrubbery creation", "home");

    AForm* robotomy = slave.makeForm("robotomy request", "fry");

    AForm* pardon = slave.makeForm("presidential pardon", "Luigi Mangione");

    AForm* none = slave.makeForm("non-existing form", "No one");

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete none;
}
