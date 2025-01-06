#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		Bureaucrat( std::string const &name, int grade );
		Bureaucrat( Bureaucrat const &b );
		Bureaucrat		&operator=( Bureaucrat const &other );
		~Bureaucrat( void );

		class GradeTooHighException : public std::exception
		{
			const char	*what( void ) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what( void ) const throw();
		};

		std::string const	&getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm ( Form &form ) const;
};

std::ostream				&operator<<( std::ostream &out, Bureaucrat const &b);

#endif
