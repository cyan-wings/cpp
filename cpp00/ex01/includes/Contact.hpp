#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestsecret;

	public:
		Contact(const std::string& firstname, const std::string& lastname,
				const std::string& nickname, const std::string& phonenumber,
				const std::string& darkestsecret);
		~Contact(void);
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickName(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getDarkestSecret(void) const;
		void				setFirstName(const std::string& firstname);
		void				setLastName(const std::string& lastname);
		void				setNickName(const std::string& nickname);
		void				setPhoneNumber(const std::string& phonenumber);
		void				setDarkestSecret(const std::string& darkestsecret);
};

constexpr int	MAX_CONTACTS = 8;

#endif
