#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_sign;
		int const			_reqSignGrade;
		int const			_reqExecGrade;

	protected:
		std::string const	_target;

		AForm( std::string const &name, int reqsigngrade, int reqexecgrade, std::string const &target );
		void				checkExecReq( Bureaucrat const &executor ) const;

	public:
		AForm( std::string const &name, int reqsigngrade, int reqexecgrade );
		AForm( AForm const &f );
		AForm const			&operator=( AForm const &other );
		~AForm( void );

		class FormException : public std::exception
		{
			public:
				virtual const char	*what ( void ) const throw() = 0;
		};

		class GradeTooHighException : public AForm::FormException
		{ const char *what( void ) const throw(); };

		class GradeTooLowException : public AForm::FormException
		{ const char *what( void ) const throw(); };

		class SignGradeTooLowException : public AForm::FormException
		{ const char *what( void ) const throw(); };

		class ExecGradeTooLowException : public AForm::FormException
		{ const char *what( void ) const throw(); };

		class ExecNotSignedException : public AForm::FormException
		{ const char *what( void ) const throw(); };

		std::string const	&getName( void ) const;
		bool				getSign( void ) const;
		int					getReqSignGrade( void ) const;
		int					getReqExecGrade( void ) const;
		void				beSigned( Bureaucrat const &b );

		virtual void		execute( Bureaucrat const &executor ) const = 0;
};

std::ostream	&operator<<( std::ostream &out, AForm const &f );

#endif