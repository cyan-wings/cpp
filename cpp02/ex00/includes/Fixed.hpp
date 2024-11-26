#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class Fixed
{
	private:
		int					_val;
		static const int	BITS = 8;

	public:
		Fixed( void );
		Fixed( const Fixed &f );
		Fixed	&operator=( const Fixed &other );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif