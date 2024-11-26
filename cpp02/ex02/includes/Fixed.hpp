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
		Fixed				&operator=( Fixed const &other );
		~Fixed( void );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		Fixed( int const n );
		Fixed( float const d );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		bool				operator>( Fixed const &other ) const;
		bool				operator<( Fixed const &other ) const;
		bool				operator>=( Fixed const &other ) const;
		bool				operator<=( Fixed const &other ) const;
		bool				operator==( Fixed const &other ) const;
		bool				operator!=( Fixed const &other ) const;
		Fixed				operator+( Fixed const &other ) const;
		Fixed				operator-( Fixed const &other ) const;
		Fixed				operator*( Fixed const &other ) const;
		Fixed				operator/( Fixed const &other ) const;
		Fixed				&operator++();
		Fixed				operator++( int );
		Fixed				&operator--();
		Fixed				operator--( int );
		static Fixed		&min( Fixed &f1, Fixed &f2 );
		static Fixed const	&min( Fixed const &f1, Fixed const &f2 );
		static Fixed		&max( Fixed &f1, Fixed &f2 );
		static Fixed const	&max( Fixed const &f1, Fixed const &f2 );
};

std::ostream	&operator<<( std::ostream &out, Fixed const &f );

#endif