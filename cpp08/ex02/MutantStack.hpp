#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void );
		MutantStack( MutantStack<T> const &ms );
		MutantStack<T>	&operator=( MutantStack<T> const &other );
		~MutantStack( void );

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

# include "MutantStack.tpp"

#endif
