#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

# include <string>
# include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};

#endif

