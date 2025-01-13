#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "AForm.hpp"
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		int				_number;
		Intern( Intern const &intern );
		Intern			&operator=( Intern const &other );

		AForm			*makePresidential(std::string const &target) const;
		AForm			*makeRobotomy(std::string const &target) const;
		AForm			*makeShrubbery(std::string const &target) const;

	public:
		Intern( void );
		~Intern( void );

		class WrongNameException : public std::exception
		{ const char	*what() const throw(); };

		AForm			*makeForm( std::string const &name, std::string const &target ) const;
};

#endif