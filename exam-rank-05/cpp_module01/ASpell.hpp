#ifndef __ASPELL_HPP__
# define __ASPELL_HPP__

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		std::string const &getName() const;
		std::string const &getEffects() const;

		virtual ASpell *clone() const = 0;
		void launch(ATarget const &target) const;
};

#endif

