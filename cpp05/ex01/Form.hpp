#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_sign;
		int const			_reqSignGrade;
		int const			_reqExecGrade;

	public:
		Form( std::string const &name, int reqsigngrade, int reqexecgrade );
		Form( Form const &f );
		Form const			&operator=( Form const &other );
		~Form( void );

		class GradeTooHighException : public std::exception
		{
			const char		*what ( void ) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char		*what ( void ) const throw();
		};

		std::string const	&getName( void ) const;
		bool				getSign( void ) const;
		int					getReqSignGrade( void ) const;
		int					getReqExecGrade( void ) const;
		void				beSigned( Bureaucrat const &b );
};

std::ostream	&operator<<( std::ostream &out, Form const &f );

#endif