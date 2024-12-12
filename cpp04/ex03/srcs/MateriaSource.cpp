#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _totaltemplates( 0 )
{
	int	i = -1;

	while ( ++i < MAX_TEMPLATES )
		_templates[i] = NULL;
}


MateriaSource::MateriaSource( MateriaSource const &materiasource ) : _totaltemplates( materiasource._totaltemplates )
{
	int	i = -1;

	while ( ++i < MAX_TEMPLATES )
		_templates[i] = materiasource._templates[i];
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &materiasource )
{
	int	i = -1;

	while ( ++i < MAX_TEMPLATES )
	{
		delete _templates[i];
		_templates[i] = materiasource._templates[i];
	}
	return ( *this );
}

MateriaSource::~MateriaSource()
{
	int	i = -1;

	while ( ++i < MAX_TEMPLATES )
	{
		delete _templates[i];
		_templates[i] = NULL;
	}
}

void	MateriaSource::learnMateria( AMateria *m )
{
	int	i = -1;

	if ( _totaltemplates == MAX_TEMPLATES )
	{
		std::cout << "MateriaSource templates full! Cannot learn materia: " << m->getType() << std::endl;
		return ;
	}
	while ( ++i < 4 )
	{
		if ( _templates[i] == NULL )
		{
			_templates[i] = m;
			++_totaltemplates;
			std::cout << "MateriaSource learnt " << m->getType() << " and stored at index: " << i << "." << std::endl;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const &type )
{
	int	i = -1;

	while ( ++i < MAX_TEMPLATES )
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	std::cout << "MateriaSource does not know " << type << " Materia." << std::endl;
	return (0);
}
