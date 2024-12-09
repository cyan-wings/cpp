#include <string>
#include <fstream>
#include <iostream>

static void	replaceWord
(
	std::ifstream& infile,
	std::ofstream& outfile,
	std::string& oldword,
	const std::string& newword
)
{
	std::string	line;
	size_t		pos;

	while ( std::getline(infile, line) )
	{
		pos = line.find(oldword);
		while ( pos != std::string::npos )
		{
			line = line.substr( 0, pos ) + newword + line.substr( pos + oldword.length() );
			pos = line.find( oldword, pos + newword.length() );
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}

int	main(int argc, char **argv)
{
	std::string	outfilename;
	std::string	oldword;
	std::string	newword;

	if (argc != 4)
		return (1);
	outfilename = std::string( argv[1] ) + ".replace";
	oldword = argv[2];
	if ( oldword.empty() )
	{
		std::cerr << "Find word is empty." << std::endl;
		return ( 0 );
	}
	newword = argv[3];
	std::ifstream infile( argv[1] );
	if ( !infile.is_open() )
	{
		std::cerr << "Open in file error." << std::endl;
		return ( 1 );
	}
	std::ofstream outfile( outfilename.c_str() );
	if ( !outfile.is_open() )
	{
		std::cerr << "Open out file error." << std::endl;
		infile.close();
		return ( 1 );
	}
	replaceWord( infile, outfile, oldword, newword );
	return ( 0 );
}