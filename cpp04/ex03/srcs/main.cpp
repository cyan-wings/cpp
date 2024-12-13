#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

void testSubject(void)
{
	std::cout << "\n>>> RUNNNING SUBJECT TESTS\n" << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	testCharacter(void)
{
	std::cout << "\n>>> TESTING CHARACTER OBJECT\n" << std::endl;
	ICharacter	*pedro = new Character("Pedro");
	ICharacter	*ivan = new Character("Ivan");
	AMateria	*ice = new Ice();
	AMateria	*tmp = new Cure();

	/* Filling Pedro's inventory */
	pedro->equip(new Ice());
	pedro->equip(ice);
	pedro->equip(new Ice());
	pedro->equip(new Cure());
	pedro->equip(tmp); // Over filling Pedro's inventory
	/* Filling Ivan's inventory */
	ivan->equip(new Cure());
	ivan->equip(new Cure());
	ivan->equip(new Ice());

	/* Using materias */
	pedro->use(0, *ivan);
	pedro->use(1, *ivan);
	pedro->use(3, *ivan);
	ivan->use(2, *pedro);

	/* Unequiping materia and use empty slot */
	pedro->unequip(1);
	pedro->use(1, *ivan);

	/* Equiping new materia and use the filled slot */
	pedro->equip(new Cure());
	pedro->use(1, *ivan);

	delete pedro;
	delete ivan;
	delete ice;
	delete tmp;
}

void	testMateriaSource()
{
	std::cout << "\n>>> TESTING MATERIASOURCE OBJECT\n" << std::endl;
	IMateriaSource	*materiaSource = new MateriaSource();
	ICharacter		*pedro = new Character("Pedro");
	ICharacter		*brandon = new Character("Brandon");
	AMateria		*tmp = new Cure();
	
	/* Learning new materias */
	materiaSource->learnMateria(new Ice());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(tmp); // Over learning items

	/* Equiping learnt materias */
	pedro->equip(materiaSource->createMateria("cure"));
	pedro->equip(materiaSource->createMateria("cure"));
	pedro->equip(materiaSource->createMateria("ice"));
	pedro->equip(materiaSource->createMateria("ice"));
	pedro->equip(materiaSource->createMateria("cure")); // Over filling Pedro's inventory

	/* Use against Brandon */
	pedro->use(0, *brandon);
	pedro->use(2, *brandon);
	
	delete materiaSource;
	delete pedro;
	delete brandon;
	delete tmp;
}

int	main(void)
{
	testSubject();
	testCharacter();
	testMateriaSource();
	return (0);
}
