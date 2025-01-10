#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void	execShrub(ShrubberyCreationForm &scf)
{
	std::cout << "Not yet sign - " << std::endl << scf;

	Bureaucrat	jack = Bureaucrat("Jack", 138);
	Bureaucrat	matthew = Bureaucrat("Matthew", 146);

	try { jack.executeForm(scf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	matthew.signForm(scf);
	std::cout << "Can't sign - " << matthew << std::endl << scf;
	matthew.incrementGrade();
	std::cout << "Matthew upgrades: " << matthew << std::endl;
	matthew.signForm(scf);
	std::cout << "Signed -" << std::endl << scf;
	matthew.signForm(scf);
	std::cout << "Can't sign again -" << std::endl << scf;
	
	try { jack.executeForm(scf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	std::cout << "Can't execute - " << jack << std::endl;
	jack.incrementGrade();
	std::cout << "Jack upgrades: " << jack << std::endl;
	jack.executeForm(scf);
}

void	execRobotomy(RobotomyRequestForm &rrf)
{
	std::cout << "Not yet sign - " << std::endl << rrf;

	Bureaucrat	jack = Bureaucrat("Jack", 46);
	Bureaucrat	matthew = Bureaucrat("Matthew", 73);

	try { jack.executeForm(rrf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	matthew.signForm(rrf);
	std::cout << "Can't sign - " << matthew << std::endl << rrf;
	matthew.incrementGrade();
	std::cout << "Matthew upgrades: " << matthew << std::endl;
	matthew.signForm(rrf);
	std::cout << "Signed -" << std::endl << rrf;
	matthew.signForm(rrf);
	std::cout << "Can't sign again -" << std::endl << rrf;
	
	try { jack.executeForm(rrf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	std::cout << "Can't execute - " << jack << std::endl;
	jack.incrementGrade();
	std::cout << "Jack upgrades: " << jack << std::endl;
	jack.executeForm(rrf);
}

void	execPardon(PresidentialPardonForm &ppf)
{
	std::cout << "Not yet sign - " << std::endl << ppf;

	Bureaucrat	jack = Bureaucrat("Jack", 6);
	Bureaucrat	matthew = Bureaucrat("Matthew", 26);

	try { jack.executeForm(ppf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	matthew.signForm(ppf);
	std::cout << "Can't sign - " << matthew << std::endl << ppf;
	matthew.incrementGrade();
	std::cout << "Matthew upgrades: " << matthew << std::endl;
	matthew.signForm(ppf);
	std::cout << "Signed -" << std::endl << ppf;
	matthew.signForm(ppf);
	std::cout << "Can't sign again -" << std::endl << ppf;
	
	try { jack.executeForm(ppf); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	std::cout << "Can't execute - " << jack << std::endl;
	jack.incrementGrade();
	std::cout << "Jack upgrades: " << jack << std::endl;
	jack.executeForm(ppf);
}

int		main( void )
{
	Intern	intern;

	AForm		*scf = intern.makeForm("Shrubbery Creation", "Sahni's Coke");
	execShrub(*static_cast<ShrubberyCreationForm *>(scf));
	delete scf;
	scf = NULL;

	std::cout << "_____________________________" << std::endl;

	AForm		*rrf = intern.makeForm("Robotomy Request", "Sahni's Butt");
	execRobotomy(*static_cast<RobotomyRequestForm *>(rrf));
	delete rrf;
	rrf = NULL;

	std::cout << "_____________________________" << std::endl;

	AForm		*ppf = intern.makeForm("Presidential Pardon", "Sahni");
	execPardon(*static_cast<PresidentialPardonForm *>(ppf));
	delete ppf;
	ppf = NULL;

	std::cout << "_____________________________" << std::endl;

	try
	{
		AForm	*wrong = intern.makeForm("Wrong Form", "Llama");
		execPardon(*static_cast<PresidentialPardonForm *>(wrong));
	}
	catch ( std::exception const &e )
	{ std::cerr << e.what() << std::endl; }

	return ( 0 );
}