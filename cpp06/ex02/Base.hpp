#ifndef __BASE_HPP__
# define __BASE_HPP__

class Base
{
	public:
		virtual ~Base( void );
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
