#include "Array.hpp"
#include "Zombie.hpp"
#include <iostream>

void	zombieTest( void )
{
	Array<Zombie>	zombies(5);

	zombies[0] = Zombie("Normal Zombie");
	zombies[1] = Zombie("Conehead Zombie");
	zombies[2] = Zombie("Buckethead Zombie");
	zombies[3] = Zombie("Football Zombie");
	zombies[4] = Zombie("Pole Vaulting Zombie");
	std::cout << "ZombieArray size: " << zombies.size() << std::endl;

	std::cout << "\nPrint all types of zombies: " << std::endl;
	std::cout << zombies << std::endl;

	std::cout << "\nPrint a valid subscript of zombies: " << std::endl;
	std::cout << zombies[2] << std::endl;

	std::cout << "\nLet's try out of bound subscript of zombies: " << std::endl;
	try
	{
		std::cout << zombies[1000] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "1000: " << e.what() << std::endl;
	}
}

int	main( void )
{
	Array<int>			intArray;
	Array<int>			copy(5);
	Array<std::string>	strArray(5);
	srand(time(0));

	for (int i = 0; i < 5; i++)
		copy[i] = rand() % 100;

	std::cout << "intArray size: " << intArray.size() << std::endl;
	std::cout << "strArray size: " << strArray.size() << std::endl;
	std::cout << "copy size: " << copy.size() << std::endl;

	std::cout << "\ncopy contents: " << copy << std::endl;
	std::cout << "intArray contents: " << intArray << std::endl;
	std::cout << "\nLet's assign copy to intArray..." << std::endl;
	intArray = copy;
	std::cout << "intArray contents: " << intArray << std::endl;

	std::cout << "\nLet's write the strArray with strings..." << std::endl;
	strArray[0] = "Lufi";
	strArray[1] = "Ace";
	strArray[2] = "Sabo";
	strArray[3] = "Dragon";
	strArray[4] = "Garp";
	std::cout << strArray << std::endl;

	std::cout << "\nLet's try getting elems out of intArray size" <<std::endl;
	try
	{
		std::cout << intArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "59: " << e.what() << std::endl;
	}

	try
	{
		std::cout << intArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-3: " << e.what() << std::endl;
	}

	zombieTest();
	return (0);
}
