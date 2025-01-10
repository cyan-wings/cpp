#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm const	&operator=( RobotomyRequestForm const &other );

	public:
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &scf );
		~RobotomyRequestForm( void );

		void execute( Bureaucrat const &executor ) const;
};

#endif