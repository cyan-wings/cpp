#include "Form.hpp"

Form::Form( std::string const &name, int reqsigngrade, int reqexecgrade ) :
_name( name ), _sign( false ), _reqSignGrade( reqsigngrade ), _reqExecGrade( reqexecgrade ) {}

Form::Form( Form const &f ) :
_name( f._name ), _sign( f._sign ), _reqSignGrade( f._reqSignGrade ), _reqExecGrade( f._reqExecGrade ) {}

Form const	&Form::operator=( Form const &other )
{
	if (_sign != other._sign)
		_sign = other._sign;
	return ( *this );
}

Form::~Form( void ) {}

char const	*Form::GradeTooHighException::what() const throw()
{
	return ( "grade too high to sign." );
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return ( "grade too low to sign." );
}

std::string const	&Form::getName( void ) const { return ( _name ); }

bool				Form::getSign( void ) const { return ( _sign ); }

int					Form::getReqSignGrade( void ) const { return ( _reqSignGrade ); }

int					Form::getReqExecGrade( void ) const { return ( _reqExecGrade ); }

void				Form::beSigned( Bureaucrat const &b )
{
	if (b.getGrade() > _reqSignGrade)
		throw Form::GradeTooLowException();
	else
		_sign = true;
}

std::ostream		&operator<<( std::ostream &out, Form const &f )
{
	out << "Form name : " << f.getName() << std::endl;
	out << "Signed : ";
	if (f.getSign())
		out << "True" << std::endl;
	else
		out << "False" << std::endl;
	out << "Required sign grade : " << f.getReqSignGrade() << std::endl;
	out << "Required execute grade : " << f.getReqExecGrade() << std::endl;
	return ( out );
}