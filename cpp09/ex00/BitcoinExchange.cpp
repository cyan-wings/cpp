#include "BitcoinExchange.hpp"

char const	*BitcoinExchange::DataFileErrorException::what( void ) const throw()
{
	return ( "error opening data file." );
}

char const	*BitcoinExchange::InputFileErrorException::what( void ) const throw()
{
	return ( "error opening input file." );
}

char const	*BitcoinExchange::DataFileFormatErrorException::what( void ) const throw()
{
	return ( "data file has wrong format." );
}

bool	BitcoinExchange::parseFile( std::string const& filename )
{
	std::ifstream	file(filename);

	if ( !file )
		return ( false );
	file.close();
	return ( true );
}

std::time_t	BitcoinExchange::parseDate( std::string const &dateStr )
{
	std::tm				tm = {};
	std::stringstream	ss(dateStr);

	ss >> std::get_time( &tm, "%Y-%m-%d" );
	if ( ss.fail() )
		throw ( DataFileFormatErrorException() );
	return ( std::mktime(&tm) );
}

void	BitcoinExchange::collectData( std::string const &data, std::map<std::time_t,double> &chart )
{
	std::ifstream	dataFile( data );
	if ( !dataFile.is_open() )
		throw ( DataFileErrorException() );

	std::string		line;
	bool			headerProcessed = false;
	while ( std::getline(dataFile, line) )
	{
		std::stringstream	ss(line);

		if ( !headerProcessed )
		{
			headerProcessed = true;
			continue;
		}
		std::string			dateStr;
		double				rate;
		std::getline(ss, dateStr, ',');
		if (dateStr.empty())
			throw ( DataFileFormatErrorException() );
		ss >> rate;
		if (ss.fail())
			throw ( DataFileFormatErrorException() );
		std::time_t		date = parseDate( dateStr );
		chart.insert( std::make_pair(date, rate) );
	}
	dataFile.close();
}

void	BitcoinExchange::printChart( std::map<std::time_t,double> const &chart )
{
	for (std::map<std::time_t, double>::const_iterator it = chart.begin(); it != chart.end(); ++it)
	{
		std::tm						*tm = std::localtime( &it->first );
		std::cout << "Date: " << std::put_time(tm, "%Y-%m-%d") << " Rate: " << it->second << std::endl;
	}
}

void	BitcoinExchange::pError( std::string const &msg )
{
	std::cout << "Error: " << msg << std::endl;
}

bool	BitcoinExchange::parseInputDate( std::string const &dateStr, std::time_t &date )
{
	if (dateStr.empty())
	{
		pError("bad input => " + dateStr);
		return ( false );
	}
	std::tm				tm = {};
	std::stringstream	ss(dateStr);
	ss >> std::get_time( &tm, "%Y-%m-%d" );
	if ( ss.fail() )
	{
		pError("bad input => " + dateStr);
		return ( false );
	}
	date = std::mktime(&tm);
	return ( true );
}

bool	BitcoinExchange::parseInputValue( std::string const &valueStr, double &value )
{
	try
	{
		value = std::stod( valueStr );
	}
	catch ( std::exception const & )
	{
		pError("bad input => " + valueStr);
		return ( false );
	}
	if ( value < 0.0 )
	{
		pError("not a positive number.");
		return ( false );
	}
	if ( value == 0.0 )
	{
		pError("cannot be 0.");
		return ( false );
	}
	if ( value > 2147483647 )
	{
		pError("too large a number.");
		return ( false );
	}
	return ( true );
}

bool	BitcoinExchange::checkDateAboveMin( std::time_t &date, std::string const &dateStr )
{
	struct tm	minTime = {};
	minTime.tm_year = 2009 - 1900;
	minTime.tm_mon = 0;
	minTime.tm_mday = 2;
	time_t		minDate = mktime(&minTime);

	if ( date < minDate )
	{
		pError( dateStr + " => btc does not exist yet." );
		return ( false );
	}
	return ( true );
}

void	BitcoinExchange::showExchange( std::ifstream &inputFile, std::map<std::time_t,double> const &chart )
{
	std::string				line;

	std::getline(inputFile, line);
	while ( std::getline(inputFile, line) )
	{
		if ( line.empty() )
			continue ;

		size_t				delimiterPos = line.find( " | " );
		if ( delimiterPos == std::string::npos )
		{
			pError("bad input => " + line);
			continue ;
		}

		std::string	dateStr = line.substr(0, delimiterPos);
		std::time_t	date;
		if ( !parseInputDate( dateStr, date ) )
			continue;
		std::string	valueStr = line.substr(delimiterPos + 3);
		double		value;
		if ( !parseInputValue( valueStr, value ) )
			continue;
		if ( !checkDateAboveMin( date, dateStr ) )
			continue;

		std::map<time_t, double>::const_iterator it = chart.find(date);
		while ( it == chart.end() )
		{
			date -= 86400;
			it = chart.find(date);
		}
		std::cout << dateStr << " => " << valueStr << " = " << it->second * value << std::endl;
	}

}

void	BitcoinExchange::run( std::string const &data, std::string const &input )
{
	if ( !parseFile(data) )
		throw ( DataFileErrorException() );
	if ( !parseFile(input) )
		throw ( InputFileErrorException() );

	std::map<std::time_t,double>	chart;
	collectData( data, chart );
	// printChart( chart );
	
	std::ifstream	inputFile( input );
	if ( !inputFile.is_open() )
		throw ( InputFileErrorException() );
	showExchange( inputFile, chart );
	inputFile.close();
}