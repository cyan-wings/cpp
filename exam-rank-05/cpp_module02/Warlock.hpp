#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

# include <string>
# include <iostream>
# include <vector>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellbook;

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spell);
		void launchSpell(std::string const &spell, ATarget const &target);
};

#endif

