#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	createShrub()
{
	ShrubberyCreationForm		scf = ShrubberyCreationForm("Sahni's Coke");
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

void	requestRobotomy()
{
	RobotomyRequestForm		rrf = RobotomyRequestForm("Sahni's Butt");
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

void	presidentialPardon()
{
	PresidentialPardonForm		ppf = PresidentialPardonForm("Sahni");
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
	createShrub();
	std::cout << "_____________________________" << std::endl;
	requestRobotomy();
	std::cout << "_____________________________" << std::endl;
	presidentialPardon();
	return ( 0 );
}