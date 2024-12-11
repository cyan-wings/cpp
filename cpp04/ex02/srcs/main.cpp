#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	testSubject( void ) {
	std::cout << "\n>>> RUNNING SUBJECT TESTS\n" << std::endl;
	/* Subject asking to create and make an array with half Dog and half Cat */
	AAnimal	*animals[4];

	for (int i = 0; i < 4; i++) {
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	/* Testing destructors order (Brain > Dog/Cat > Animal) */
	std::cout << "Filling done. Deleting every Animal..." << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	/* Provided by subject */
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	delete j;
	delete i;
}

void	testDeepCopy( void ) {
	std::cout << "\n>>> RUNNING DEEPCOPY TESTS\n" << std::endl;
	std::cout << "--- Dog's behavior ---" << std::endl;
	Dog	dogA;
	Dog dogB;

	std::cout << "-------" << std::endl;
	dogA.getBrain()->_ideas[0] = "DogA's idea";
	dogB.getBrain()->_ideas[0] = "DogB's idea";
	std::cout << "DogA's address (" << &dogA << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogA.getBrain()->_ideas[0] << " (" << &dogA.getBrain()->_ideas[0] << ")" << std::endl;
	std::cout << "DogB's address (" << &dogB << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogB.getBrain()->_ideas[0] <<" (" << &dogB.getBrain()->_ideas[0] << ")" << std::endl;

	std::cout << "-------" << std::endl;
	dogB = dogA;
	std::cout << "DogA's address (" << &dogA << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogA.getBrain()->_ideas[0] << " (" << &dogA.getBrain()->_ideas[0] << ")" << std::endl;
	std::cout << "DogB's address (" << &dogB << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogB.getBrain()->_ideas[0] <<" (" << &dogB.getBrain()->_ideas[0] << ")" << std::endl;

	std::cout << "--- Cat's behavior ---" << std::endl;
	Cat	catA;
	Cat catB;

	std::cout << "-------" << std::endl;
	catA.getBrain()->_ideas[0] = "CatA's idea";
	catB.getBrain()->_ideas[0] = "CatB's idea";
	std::cout << "CatA's address (" << &catA << ")..." << std::endl;
	std::cout << "    idea[0]=" << catA.getBrain()->_ideas[0] << " (" << &catA.getBrain()->_ideas[0] << ")" << std::endl;
	std::cout << "CatB's address (" << &catB << ")..." << std::endl;
	std::cout << "    idea[0]=" << catB.getBrain()->_ideas[0] <<" (" << &catB.getBrain()->_ideas[0] << ")" << std::endl;

	std::cout << "-------" << std::endl;
	catB = catA;
	std::cout << "CatA's address (" << &catA << ")..." << std::endl;
	std::cout << "    idea[0]=" << catA.getBrain()->_ideas[0] << " (" << &catA.getBrain()->_ideas[0] << ")" << std::endl;
	std::cout << "CatB's address (" << &catB << ")..." << std::endl;
	std::cout << "    idea[0]=" << catB.getBrain()->_ideas[0] <<" (" << &catB.getBrain()->_ideas[0] << ")" << std::endl;
}

int	main( void )
{
	//AAnimal test;
	testSubject();
	testDeepCopy();
	return ( 0 );
}
