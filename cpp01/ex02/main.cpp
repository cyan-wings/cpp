#include <iomanip>
#include <iostream>
#include <string>

int main( void )
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "memory address of my_string: " << &stringVAR << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "memory address of str_ptr: " << stringPTR << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "memory address of str_ref: " << &stringREF << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "value of stringVAR: " << stringVAR << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "value of stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(29)
			<< "value of stringREF: " << stringREF << std::endl;
}
