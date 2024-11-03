#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name);
};

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

Zombie	*zombieHorde(int N, std::string name);

#endif