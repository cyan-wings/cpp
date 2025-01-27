#ifndef __FWOOSH_HPP__
# define __FWOOSH_HPP__

# include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		
		ASpell *clone() const;
};

#endif

