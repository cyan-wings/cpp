#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm( std::string const &target )
:
AForm( "Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &scf )
:
AForm( "Robotomy Request Form", 72, 45, scf._target) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	checkExecReq(executor);
	std::cout << "Bzzz..." << std::endl;
	srand(static_cast<unsigned int>(time(0)));
	if (rand() % 2 == 0)
		std::cout << _target << "is robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}