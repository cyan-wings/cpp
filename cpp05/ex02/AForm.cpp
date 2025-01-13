#include "AForm.hpp"

AForm::AForm( std::string const &name, int reqsigngrade, int reqexecgrade ) :
_name( name ), _sign( false ), _reqSignGrade( reqsigngrade ), _reqExecGrade( reqexecgrade )
{
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
		throw AForm::GradeTooHighException();
	if (_reqSignGrade > 150 || _reqExecGrade > 150 )
		throw AForm::GradeTooLowException();
}

AForm::AForm( std::string const &name, int reqsigngrade, int reqexecgrade, std::string const &target) :
_name( name ), _sign( false ), _reqSignGrade( reqsigngrade ), _reqExecGrade( reqexecgrade ), _target( target )
{
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
		throw AForm::GradeTooHighException();
	if (_reqSignGrade > 150 || _reqExecGrade > 150 )
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const &f ) :
_name( f._name ), _sign( f._sign ), _reqSignGrade( f._reqSignGrade ), _reqExecGrade( f._reqExecGrade ), _target( f._target ) {}

AForm 		&AForm::operator=( AForm const &other )
{
	if (_sign != other._sign)
		_sign = other._sign;
	return ( *this );
}

AForm::~AForm( void ) {}

char const	*AForm::GradeTooHighException::what() const throw()
{
	return ( "Grade set too high." );
}

char const	*AForm::GradeTooLowException::what() const throw()
{
	return ( "Grade set too low." );
}

char const *AForm::SignGradeTooLowException::what() const throw()
{
	return ( "Grade too low to sign." );
}

char const *AForm::ExecGradeTooLowException::what() const throw()
{
	return ( "Grade too low to execute." );
}

char const *AForm::ExecNotSignedException::what() const throw()
{
	return ( "Form not yet signed to be executed." );
}

std::string const	&AForm::getName( void ) const { return ( _name ); }

bool				AForm::getSign( void ) const { return ( _sign ); }

int					AForm::getReqSignGrade( void ) const { return ( _reqSignGrade ); }

int					AForm::getReqExecGrade( void ) const { return ( _reqExecGrade ); }

void				AForm::beSigned( Bureaucrat const &b )
{
	if (b.getGrade() > _reqSignGrade)
		throw AForm::SignGradeTooLowException();
	else
		_sign = true;
}

std::ostream		&operator<<( std::ostream &out, AForm const &f )
{
	out << "AForm name : " << f.getName() << std::endl;
	out << "Signed : ";
	if (f.getSign())
		out << "True" << std::endl;
	else
		out << "False" << std::endl;
	out << "Required sign grade : " << f.getReqSignGrade() << std::endl;
	out << "Required execute grade : " << f.getReqExecGrade() << std::endl;
	return ( out );
}

void				AForm::checkExecReq( Bureaucrat const &executor ) const
{
	if (_sign != true)
		throw AForm::ExecNotSignedException();
	if (executor.getGrade() > _reqExecGrade)
		throw AForm::ExecGradeTooLowException();
}

