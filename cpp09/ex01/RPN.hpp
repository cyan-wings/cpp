#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <string>
# include <stack>
# include <sstream>
# include <iostream>

class RPN
{
	private:
		RPN( void );
		RPN( RPN const & rpn );
		RPN				&operator=( RPN const &other );
		~RPN( void );

		static bool		parseInput( std::string const &input );
		static int		convertInt( std::string const &digitStr );
		static int		calcOperation( int val1, int val2, std::string const &symbol );

	public:
		static void	compute( std::string const &input );

		class RPNInputException : public std::exception
		{
			public:
				char const	*what( void ) const throw();
		};
};

#endif
