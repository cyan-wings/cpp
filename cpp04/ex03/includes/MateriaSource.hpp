#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include "IMateriaSource.hpp"
# include <string>

# define MAX_TEMPLATES 4

class MateriaSource : public IMateriaSource
{
	private:
		int			_totaltemplates;
		AMateria	*_templates[MAX_TEMPLATES];

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &materiasource );
		MateriaSource	&operator=( MateriaSource const &other );
		virtual ~MateriaSource( void );

		virtual void		learnMateria( AMateria* m );
		virtual AMateria*	createMateria( std::string const &type );
};

#endif