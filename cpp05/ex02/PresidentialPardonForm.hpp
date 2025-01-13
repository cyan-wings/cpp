#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm	&operator=( PresidentialPardonForm const &other );

	public:
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &scf );
		~PresidentialPardonForm( void );

		void					execute( Bureaucrat const &executor ) const;
};

#endif