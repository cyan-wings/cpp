#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() { _spells.clear(); }

void SpellBook::learnSpell(ASpell *spell)
{
	std::vector<ASpell *>::iterator ite = _spells.end();

        for (std::vector<ASpell *>::iterator it = _spells.begin(); it != ite; ++it)
        {
                if ((*it)->getName() == spell->getName())
                        return ;
        }
        _spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::vector<ASpell *>::iterator ite = _spells.end();

        for (std::vector<ASpell *>::iterator it = _spells.begin(); it != ite; ++it)
        {
                if ((*it)->getName() == spell)
                {
                        _spells.erase(it);
                        return;
                }
        }
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	std::vector<ASpell *>::iterator ite = _spells.end();

        for (std::vector<ASpell *>::iterator it = _spells.begin(); it != ite; ++it)
        {
                if ((*it)->getName() == spell)
                        return ((*it)->clone());
        }
	return (NULL);
}
