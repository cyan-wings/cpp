#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void	wrongMain( void )
{
	const WrongAnimal	*wa = new WrongAnimal();

	std::cout << wa->getType() << " " << std::endl;
	wa->makeSound();
	delete wa;
	wa = new WrongCat();
	std::cout << wa->getType() << " " << std::endl;
	wa->makeSound();
	delete wa;
}

int	main( void )
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "\n>>> RUNNNING WRONGMAIN TESTS\n" << std::endl;
	wrongMain();
	delete meta;
	delete j;
	delete i;
	return (0);
}