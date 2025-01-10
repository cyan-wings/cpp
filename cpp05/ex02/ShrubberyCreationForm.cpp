#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target )
:
AForm( "Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &scf )
:
AForm( "Shrubbery Creation Form", 145, 137, scf._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void						ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	checkExecReq(executor);
	std::string		outfile = _target + "_shrubbery";
	std::ofstream	output(outfile.c_str());
	
	output << "       _-_" << std::endl;
	output << "    /~~   ~~\\" << std::endl;
	output << " /~~         ~~\\" << std::endl;
	output << "{               }" << std::endl;
	output << " \\  _-     -_  /" << std::endl;
	output << "   ~  \\ //  ~" << std::endl;
	output << "_- -   | | _- _" << std::endl;
	output << "  _ -  | |   -_" << std::endl;
	output << "      // \\\\" << std::endl;
}