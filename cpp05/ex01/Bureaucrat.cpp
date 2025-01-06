#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const &name, int grade ) : _name( name ), _grade( grade )
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const &b ) : _name( b._name ), _grade( b._grade ) {}

Bureaucrat		&Bureaucrat::operator=( Bureaucrat const &other )
{
	if (_grade != other._grade)
		_grade = other._grade;
	return ( *this );
}

Bureaucrat::~Bureaucrat() {}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Grade cannot be higher than 1. " );
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Grade cannot be lower than 150." );
}

std::string const	&Bureaucrat::getName( void ) const { return ( _name ); }

int					Bureaucrat::getGrade( void ) const { return ( _grade ); }

void				Bureaucrat::incrementGrade( void )
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void				Bureaucrat::decrementGrade( void )
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

void				Bureaucrat::signForm( Form &form ) const
{
	if (form.getSign())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because already signed." << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		if (form.getSign())
			std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch ( std::exception const &e )
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream		&operator<<( std::ostream &out, Bureaucrat const &b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return ( out );
}