#include "MutantStack.hpp"
#include <iostream>
#include <list>

static void	givenTest( void )
{
	MutantStack<int>			mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void	givenTest2( void )
{
	std::list<int>			mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator	it = mstack.begin();
	std::list<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

static void	selfTest( void )
{
	MutantStack<int> mstack;

	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	mstack.push(40);
	mstack.push(50);

	std::cout << "Forward iteration:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Reverse iteration:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << std::endl;

	std::cout << "Top of the stack: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "After pop, top of the stack: " << mstack.top() << std::endl;
}

int	main( void )
{
	std::cout << "Given test by assignment:" << std::endl;
	givenTest();
	std::cout << "_________________________" << std::endl << std::endl;
	std::cout << "Testing with std::list (outputs must be the same as the given test):" << std::endl;
	givenTest2();
	std::cout << "_________________________" << std::endl << std::endl;
	std::cout << "Self test:" << std::endl;
	selfTest();
	return ( 0 );
}


