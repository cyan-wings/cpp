#include "MateriaSource.hpp"
#include <iostream>

void	MateriaSource::deleteTemplates()
{
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (this->_templates[i]) {
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource() : _idx( 0 ) {}

MateriaSource::MateriaSource( MateriaSource const &materiasource ) : _idx( materiasource._idx ), _templates( materiasource._templates )
{
	deleteTemplates();
	*this = materiaSource;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &materiasource )
{
	deleteTemplates();
	for (int i = 0; i < MAX_TEMPLATES; i++)
	{
		if (materiasource._templates[i])
			_templates[i] = materiasource._templates[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource() { deleteTemplates(); }

void	MateriaSource::learnMateria( AMateria* materia )
{
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (!_templates[i])
		{
			_templates[i] = materia;
			std::cout << "Learnt new materia: " << materia->getType() << "." << std::endl;
			return ;
		}
	}
	std::cout << BYEL "[MateriaSource] " CRESET "Couldn't learn new material " BCYN << \
		materia->getType() << CRESET "..." << std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (this->_templates[i] && this->_templates[i]->getType() == type)
			return (this->_templates[i]->clone());
	}
	return (0);
}

