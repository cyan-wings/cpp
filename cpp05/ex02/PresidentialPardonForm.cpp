#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm( std::string const &target )
:
AForm( "Presidential Pardon Form", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &scf )
:
AForm( "Presidential Pardon Form", 25, 5, scf._target) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	checkExecReq(executor);
	std::cout << _target << " pardoned by Zaphod Beeblebrox." << std::endl;
}