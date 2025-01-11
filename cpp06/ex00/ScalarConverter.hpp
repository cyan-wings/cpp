#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &sc );
		ScalarConverter const	&operator=( ScalarConverter const &other );
		~ScalarConverter( void );

		static void				disError( std::string const &param );
		static void				disPosInf( void );
		static void				disNegInf( void );
		static void				disNan( void );
		static void				disChar( char c );
		static void				disInt( std::string const &param );
		static void				disFloat( std::string const &param );
		static void				disDouble( std::string const &param );
		static bool				parseInput( std::string const &param, int &periodCount );

	public:
		static void				convert( std::string const &param );
};

#endif