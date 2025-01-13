#ifndef __MUTANTSTACK_TPP__
# define __MUTANTSTACK_TPP__

template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack( MutantStack<T> const &ms ) : std::stack<T>( ms ) {}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=( MutantStack<T> const &other )
{
	if ( this != other )
		std::stack<T>::operator=(other);
	return ( *this );
}

template <typename T>
MutantStack<T>::~MutantStack( void ) {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return ( this->c.begin() ); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return ( this->c.end() ); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() { return ( this->c.rbegin() ); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() { return ( this->c.rend() ); }

#endif
