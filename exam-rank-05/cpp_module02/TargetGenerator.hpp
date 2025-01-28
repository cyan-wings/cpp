#ifndef __TARGETGENERATOR_HPP__
# define __TARGETGENERATOR_HPP__

# include <vector>
# include <string>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::vector<ATarget *> _targets;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &target);
		ATarget *createTarget(std::string const &target);
};

#endif

