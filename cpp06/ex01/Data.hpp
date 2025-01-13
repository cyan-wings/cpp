#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <string>
# include <iostream>

class Data
{
	private:
		std::string			_meta;

	public:
		Data( std::string const &meta );
		Data( Data const &d );
		Data				&operator=( Data const &other );
		~Data( void );

		std::string const	&getData( void ) const;
};

std::ostream				&operator<<( std::ostream &out, Data const &d );

#endif
