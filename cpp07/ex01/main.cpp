#include "iter.hpp"
#include <iostream>

void	printInt(int &element) { std::cout << element << " "; }

void	printFloat(float &element) { std::cout << element << " "; }

void	printString(std::string &element) { std::cout << element << " "; }

int main()
{
	int			intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Integer Array: ";
	iter(intArray, sizeof(intArray) / sizeof(intArray[0]), printInt);
	std::cout << std::endl;

	float		floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::cout << "Float Array: ";
	iter(floatArray, sizeof(floatArray) / sizeof(floatArray[0]), printFloat);
	std::cout << std::endl;

	std::string	stringArray[] = {"Hello", "world", "this", "is", "C++"};
	std::cout << "String Array: ";
	iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), printString);
	std::cout << std::endl;

	return (0);
}
