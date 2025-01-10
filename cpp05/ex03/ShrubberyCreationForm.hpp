#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm const	&operator=( ShrubberyCreationForm const &other );

	public:
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &scf );
		~ShrubberyCreationForm( void );

		void execute( Bureaucrat const &executor ) const;
};

#endif