#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

//Consider calling cout in Constructor to print itself.
int	main( void )
{
	try { Form	fail1 = Form("Fail1", 1, 0); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try { Form	fail2 = Form("Fail2", 0, 1); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try { Form	fail3 = Form("Fail3", 0, 0); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	try { Form	fail4 = Form("Fail4", 150, 151); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try { Form	fail5 = Form("Fail5", 151, 150); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try { Form	fail6 = Form("Fail6", 151, 151); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	try { Form	fail7 = Form("Fail7", 0, 151); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }
	try { Form	fail8 = Form("Fail8", 151, 0); }
	catch ( std::exception const &e ) { std::cerr << e.what() << std::endl; }

	Form		toBeSigned = Form("Something to sign", 50, 50);
	std::cout << "Not yet sign - " << std::endl << toBeSigned;
	Bureaucrat	matthew = Bureaucrat("Matthew", 51);
	matthew.signForm(toBeSigned);
	std::cout << "Can't sign -" << std::endl << toBeSigned;
	matthew.incrementGrade();
	matthew.signForm(toBeSigned);
	std::cout << "Signed -" << std::endl << toBeSigned;
	matthew.signForm(toBeSigned);
	std::cout << "Can't sign again -" << std::endl << toBeSigned;
	Form	dummyForm = Form("Dummy to copy", 100, 100);
	dummyForm = toBeSigned;
	std::cout << dummyForm;

	return ( 0 );
}