#ifndef __BRICKWALL_HPP__
# define __BRICKWALL_HPP__

# include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		
		ATarget *clone() const;
};

#endif

