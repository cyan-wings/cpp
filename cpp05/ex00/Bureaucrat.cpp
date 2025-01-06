#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( name, grade ) : _name( name ), _grade( grade )
{
	;
}

Bureaucrat::Bureaucrat( Bureaucrat const &b )
{
	*this = b;
}

Bureaucrat		&Bureaucrat::operator=( Bureaucrat const &other )
{
	if (_name != other._name)
		_name = other._name;
	if (_grade != other._grade)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const	&getName( void ) const { return (_name); }

int const		&getGrade( void ) const { return (_grade); }

void			incrementGrade( int increment )
{
	int	res = _grade - increment;

	if (res < 1)

