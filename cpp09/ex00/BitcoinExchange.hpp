#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <string>
#include <map>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange
{
	private:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &be );
		BitcoinExchange			&operator=( BitcoinExchange const &other );
		~BitcoinExchange( void );

		static bool				parseFile( std::string const& filename );
		static std::time_t		parseDate( std::string const &dateStr );
		static void				collectData( std::string const &data, std::map<std::time_t,double> &chart );
		static void				printChart( std::map<std::time_t,double> const &chart );
		static void				pError( std::string const &msg );
		static bool				parseInputDate( std::string const &dateStr, std::time_t &date );
		static bool				stod_safe(const std::string& str, double& out);
		static bool				parseInputValue( std::string const &valueStr, double &value );
		static bool				checkDateAboveMin( std::time_t &date, std::string const &dateStr );
		static void				showExchange( std::ifstream &inputFile, std::map<std::time_t,double> const &chart );

	public:
		static void				run( std::string const &data, std::string const &input );
		//test with const later

		class DataFileErrorException : public std::exception
		{
			char const	*what( void ) const throw();
		};
		class InputFileErrorException : public std::exception
		{
			char const	*what( void ) const throw();
		};
		class DataFileFormatErrorException : public std::exception
		{
			char const	*what( void ) const throw();
		};
};

#endif
