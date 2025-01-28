#ifndef __FIREBALL_HPP__
# define __FIREBALL_HPP__

# include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		
		ASpell *clone() const;
};

#endif

