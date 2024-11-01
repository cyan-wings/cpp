#include "PhoneBook.hpp"
#include <iostream>

static void	getInput(const std::string& field, std::string& buffer)
{
	while (true)
	{
		std::cout << "Please enter " << field << ": ";
		std::cin >> buffer;
		if (buffer.empty())
			std::cout << "Field can't be empty." << std::endl;
		else
			break ;
	}
}


void	PhoneBook::add(void)
{
	std::string	buf;
	Contact		contact("", "", "", "", "");

	if (_index == MAX_CONTACTS)
	{
		std::cout << "Warning: Contact " << _contact_array[0].getFirstName()
				<< " will be replaced." << std::endl;
		_index = 0;
	}
	std::cout << "Adding a new contact..." << std::endl;
	getInput("first name", buf);
	contact.setFirstName(buf);
	getInput("last name", buf);
	contact.setLastName(buf);
	getInput("nickname", buf);
	contact.setNickName(buf);
	getInput("phone number", buf);
	contact.setPhoneNumber(buf);
	getInput("darkest secret", buf);
	contact.setDarkestSecret(buf);
	_contact_array[_index++] = contact;
}

void	PhoneBook::search(void)
{
	
}