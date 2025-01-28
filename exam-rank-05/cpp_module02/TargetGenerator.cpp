#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() { _targets.clear(); }

void TargetGenerator::learnTargetType(ATarget *target)
{
	std::vector<ATarget *>::iterator ite = _targets.end();

        for (std::vector<ATarget *>::iterator it = _targets.begin(); it != ite; ++it)
        {
                if ((*it)->getType() == target->getType())
                        return ;
        }
        _targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	std::vector<ATarget *>::iterator ite = _targets.end();

        for (std::vector<ATarget *>::iterator it = _targets.begin(); it != ite; ++it)
        {
                if ((*it)->getType() == target)
                {
                        _targets.erase(it);
                        return;
                }
        }
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	std::vector<ATarget *>::iterator ite = _targets.end();

        for (std::vector<ATarget *>::iterator it = _targets.begin(); it != ite; ++it)
        {
                if ((*it)->getType() == target)
                        return ((*it)->clone());
        }
	return (NULL);
}

