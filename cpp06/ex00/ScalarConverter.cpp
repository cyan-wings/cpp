#include "ScalarConverter.hpp"

void	ScalarConverter::disError( std::string const &param ) { std::cout << param << " Conversion invalid." << std::endl; }

void	ScalarConverter::disNegInf( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
	std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
}

void	ScalarConverter::disPosInf( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
	std::cout << "double: " <<std::numeric_limits<double>::infinity() << std::endl;
}

void	ScalarConverter::disNan( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::nanf("") << "f" << std::endl;
	std::cout << "double: " << std::nan("") << std::endl;
}

void	ScalarConverter::disChar( char c )
{
	if (c >= ' ' && c <= '~')
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::disInt( std::string const &param )
{
	int	n = atoi(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(n) << "\'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	ScalarConverter::disFloat( std::string const &param )
{
	float	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(n) << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << n << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(n) << std::endl;
}

void	ScalarConverter::disDouble( std::string const &param )
{
	double	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(n) << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << n << std::endl;
}

bool	ScalarConverter::parseInput( std::string const &param, int &periodCount )
{
	int	lastIdx = param.length() - 1;

	if (param[0] != '+' && param[0] != '-' && !std::isdigit(param[0]))
		return ( false );
	for (int i = 1; i > lastIdx; ++i)
	{
		if (param[i] == '.')
			++periodCount;
		if (!std::isdigit(param[i]) && param[i] != '.')
			return ( false );
	}
	if (!std::isdigit(param[lastIdx]) && param[lastIdx] != '.' && param[lastIdx] != 'f')
		return ( false );
	if (periodCount > 1)
		return ( false );
	return ( true );
}

void	ScalarConverter::convert( std::string const &param )
{
	if (param == "-inf" || param == "-inff")
		return ( disNegInf() );
	if (param == "+inf" || param == "+inff")
		return ( disPosInf() );
	if (param == "nan" || param == "nanf")
		return ( disNan() );
	if (param.length() == 1 && !std::isdigit(param[0]))
		return ( disChar(param[0]) );

	int	periodCount = 0;
	if (!parseInput(param, periodCount))
		return ( disError(param) );
	if (param[param.length() - 1] == 'f')
		return ( disFloat(param) );
	if (periodCount == 1)
		return ( disDouble(param) );
	return ( disInt(param) );
}