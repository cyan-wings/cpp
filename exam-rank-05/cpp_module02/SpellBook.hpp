#ifndef __SPELLBOOK_HPP__
# define __SPELLBOOK_HPP__

# include <vector>
# include <string>
# include "ASpell.hpp"

class SpellBook
{
	private:
		std::vector<ASpell *> _spells;

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spell);
		ASpell *createSpell(std::string const &spell);
};

#endif

