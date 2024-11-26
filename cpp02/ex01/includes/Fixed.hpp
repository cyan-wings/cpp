#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class Fixed
{
	private:
		int					_val;
		static int const	BITS = 8;

	public:
		Fixed( void );
		Fixed( Fixed const &f );
		Fixed	&operator=( Fixed const &other );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed( int const n );
		Fixed( float const d );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<( std::ostream &out, Fixed const &f );

#endif