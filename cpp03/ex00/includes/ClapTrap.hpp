#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_att;

		bool		checkStatus( void );
		void		printHp( void );
		void		printEp( void );

	public:
		ClapTrap( void );
		ClapTrap( ClapTrap const &ct );
		ClapTrap	&operator=( ClapTrap const &other );
		~ClapTrap( void );
		ClapTrap( std::string const &name );
		void		attack( std::string const &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

#endif