#ifndef __POLYMORPH_HPP__
# define __POLYMORPH_HPP__

# include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		
		ASpell *clone() const;
};

#endif

