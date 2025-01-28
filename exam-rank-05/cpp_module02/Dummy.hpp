#ifndef __DUMMY_HPP__
# define __DUMMY_HPP__

# include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		
		ATarget *clone() const;
};

#endif

