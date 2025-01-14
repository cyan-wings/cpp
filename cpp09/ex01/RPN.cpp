#include "RPN.hpp"

bool	RPN::parseInput( std::string const &input )
{
	std::stringstream	ss(input);
	std::string			token;

	while ( ss >> token )
	{
		if ( token.length() != 1 )
			return ( false );
		if ( !isdigit(token[0]) && token != "+" && token != "-" && token != "*" && token != "/" )
			return ( false );
	}
	return ( true );
}

int	RPN::convertInt( std::string const &digitStr )
{
	std::stringstream	ss(digitStr);
	int					value;

	ss >> value;
	if (ss.fail())
		throw ( RPNInputException() );
	return ( value );
}

int		RPN::calcOperation( int val1, int val2, std::string const &symbol )
{
	if ( symbol == "+" )
		return ( val1 + val2 );
	if ( symbol == "-" )
		return ( val1 - val2 );
	if ( symbol == "*" )
		return ( val1 * val2 );
	if ( symbol == "/" )
	{
		if ( val2 == 0 )
			throw ( RPNInputException() );
		return ( val1 / val2 );
	}
	throw ( RPNInputException() );
}

char const	*RPN::RPNInputException::what( void ) const throw()
{
	return ( "Error" );
}

void	RPN::compute( std::string const &input )
{
	std::stack<int>	buffer;
	std::stringstream	ss(input);
	std::string			token;

	if ( !parseInput( input ) )
		throw ( RPNInputException() );
	while ( ss >> token )
	{
		if ( isdigit(token[0]) )
		{
			buffer.push( convertInt( token ) );
			continue ;
		}
		if ( buffer.empty() )
			throw ( RPNInputException() );
		int		val1 = buffer.top(); buffer.pop();
		int		val2 = buffer.top(); buffer.pop();
		buffer.push( calcOperation( val2, val1, token ) );
	}
	std::cout << buffer.top() << std::endl;
}
