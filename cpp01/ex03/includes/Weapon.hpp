#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon( const std::string& type );
		~Weapon( void );
		const std::string&	getType( void ) const;
		void				setType( const std::string& type );
};

#endif