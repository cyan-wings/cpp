#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

void	simpleTest( void )
{
	std::list<int>				lst;
	std::list<int>::iterator	ret;

	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(32);
	lst.push_back(15);

	try
	{
		ret = easyfind(lst, 32);
		std::cout << "Value found: " << *ret << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ret = easyfind(lst, 33);
		std::cout << "Value found: " << *ret << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	complexTest( void )
{
	std::vector<int>				vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	try
	{
		std::vector<int>::iterator	result = easyfind(vec, 30);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator	result = easyfind(vec, 60);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::list<int>					lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);
	lst.push_back(400);
	lst.push_back(500);

	try
	{
		std::list<int>::iterator	result = easyfind(lst, 300);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator	result = easyfind(lst, 60);
		std::cout << "Found value: " << *result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main( void )
{
	std::cout << "Running simple test:" << std::endl;
	simpleTest();
	std::cout << "_____________________" << std::endl << std::endl;
	std::cout << "Running complex test:" << std::endl;
	complexTest();
	return ( 0 );
}