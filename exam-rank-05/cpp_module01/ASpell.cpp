#include "ASpell.hpp"

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {};

std::string const &ASpell::getName() const { return _name; }

std::string const &ASpell::getEffects() const { return _effects; }

void ASpell::launch(ATarget const &target) const { target.getHitBySpell(*this); }
