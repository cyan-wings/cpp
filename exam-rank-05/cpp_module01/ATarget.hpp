#ifndef __ATARGET_HPP__
# define __ATARGET_HPP__

# include <string>
# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string _type;

	public:
		ATarget(std::string const &type);
		virtual ~ATarget();
		
		std::string const &getType() const;
		virtual ATarget *clone() const = 0;

		void getHitBySpell(ASpell const &spell) const;
};

#endif

