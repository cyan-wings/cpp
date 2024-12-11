#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>

class Brain
{
	public:
		std::string	_ideas[100];

		Brain( void );
		Brain( Brain const &brain );
		Brain		&operator=( Brain const &other );
		~Brain( void );
};

#endif
