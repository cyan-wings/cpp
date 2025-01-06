#include "Bureaucrat.hpp"
#include <iostream>

int	main( void )
{
	try { Bureaucrat	fail1 = Bureaucrat("Fail1", 0); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	try { Bureaucrat	fail2 = Bureaucrat("Fail2", 151); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	Bureaucrat	matthew = Bureaucrat("Matthew", 50);
	Bureaucrat	joe = Bureaucrat("Joe", 100);
	joe = matthew;
	Bureaucrat	copy = Bureaucrat(matthew);
	std::cout << matthew << std::endl;
	std::cout << joe << std::endl;
	std::cout << copy << std::endl;

	try
	{
		std::cout << "Before: " << matthew << std::endl;
		matthew.incrementGrade();
		std::cout << "After: " << matthew << std::endl;
	}
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try
	{
		std::cout << "Before: " << matthew << std::endl;
		matthew.decrementGrade();
		std::cout << "After: " << matthew << std::endl;
	}
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	Bureaucrat	newbie = Bureaucrat("Newbie", 150);
	try
	{
		std::cout << "Before: " << newbie << std::endl;
		newbie.decrementGrade();
		std::cout << "After: " << newbie << std::endl;
	}
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	Bureaucrat	pm = Bureaucrat("PM", 1);
	try
	{
		std::cout << "Before: " << pm << std::endl;
		pm.incrementGrade();
		std::cout << "After: " << pm << std::endl;
	}
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	return ( 0 );
}