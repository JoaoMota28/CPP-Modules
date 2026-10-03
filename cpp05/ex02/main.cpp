#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    // TEST 1: ShrubberyCreationForm

    try
    {
        Bureaucrat demeter("Demeter", 140);
        ShrubberyCreationForm shrubbery("Olympus");
        std::cout << shrubbery;
        demeter.signForm(shrubbery);
        demeter.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 2: ShrubberyCreationForm — execute without signing first

    try
    {
        Bureaucrat hephaestus("Hephaestus", 1);
        ShrubberyCreationForm shrubbery("Forge");
        hephaestus.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 3: ShrubberyCreationForm — grade too low to sign

    try
    {
        Bureaucrat sisyphus("Sisyphus", 150);
        ShrubberyCreationForm shrubbery("Tartarus");
        sisyphus.signForm(shrubbery);
        sisyphus.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 4: RobotomyRequestForm — successful sign and execute

    try
    {
        Bureaucrat ares("Ares", 45);
        RobotomyRequestForm robotomy("Achilles");
        ares.signForm(robotomy);
        ares.executeForm(robotomy);
        ares.executeForm(robotomy);
        ares.executeForm(robotomy);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 5: RobotomyRequestForm — grade too low to execute

    try
    {
        Bureaucrat hermes("Hermes", 72);
        RobotomyRequestForm robotomy("Icarus");
        hermes.signForm(robotomy);
        hermes.executeForm(robotomy);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 6: PresidentialPardonForm — successful sign and execute

    try
    {
        Bureaucrat zeus("Zeus", 1);
        PresidentialPardonForm pardon("Prometheus");
        std::cout << pardon;
        zeus.signForm(pardon);
        zeus.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 7: PresidentialPardonForm — grade too low to sign

    try
    {
        Bureaucrat apollo("Apollo", 30);
        PresidentialPardonForm pardon("Orpheus");
        apollo.signForm(pardon);
        apollo.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // TEST 8: executeForm via AForm pointer — polymorphism check

    try
    {
        Bureaucrat zeus("Zeus", 1);

        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("Elysium");
        forms[1] = new RobotomyRequestForm("Medusa");
        forms[2] = new PresidentialPardonForm("Sisyphus");

        for (int i = 0; i < 3; i++)
        {
            zeus.signForm(*forms[i]);
            zeus.executeForm(*forms[i]);
        }
        for (int i = 0; i < 3; i++)
            delete forms[i];
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
