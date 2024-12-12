#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include "IMateriaSource.hpp"
# include <string>

# define MAX_TEMPLATES 4

class MateriaSource : public IMateriaSource
{
	private:
		int			_idx;
		AMateria	*_templates[MAX_TEMPLATES];

		void		deleteTemplates(void);

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &materiasource );
		MateriaSource	&operator=( MateriaSource const &other );
		~MateriaSource( void );

		virtual void		learnMateria( AMateria* materia );
		virtual AMateria*	createMateria( std::string const &type );
};

#endif