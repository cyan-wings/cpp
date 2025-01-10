#include "Intern.hpp"

Intern::Intern( void ) : _number(0) {}

Intern::~Intern( void ) {}

AForm	*Intern::makeForm( std::string const &name, std::string const &target ) const
{
	AForm		*form = NULL;
	AForm		*(Intern::*funcPtr[3])(std::string const &target) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string	forms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	int			i = -1;

	while (++i < 3) {
		if (forms[i] == name) {
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern created " << form->getName() << "." << std::endl;
			return (form);
		}
	}
	std::cout << name << " Form failed to be created by Intern." << std::endl;
	throw Intern::WrongNameException();
	return ( NULL );
}

AForm *			Intern::makePresidential(std::string const &target) const {
	AForm	*form = new PresidentialPardonForm(target);
	return ( form );
}

AForm *			Intern::makeRobotomy(std::string const &target) const {
	AForm	*form = new RobotomyRequestForm(target);
	return ( form );
}

AForm *			Intern::makeShrubbery(std::string const &target) const {
	AForm	*form = new ShrubberyCreationForm(target);
	return ( form );
}

const char *	Intern::WrongNameException::what() const throw() {
	return ("Invalid form name.");
}