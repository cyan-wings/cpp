#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook(void) : _index(0), _total(0)
{
	std::cout << "Welcome to PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Bye~" << std::endl;
}

static void	getInput(const std::string& field, std::string& buffer)
{
	while (true)
	{
		std::cout << "Please enter " << field << ": ";
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << "End of input detected." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
		if (buffer.empty())
		{
			std::cout << "Field can't be empty." << std::endl;
			continue ;
		}
		break ;
	}
}

void	PhoneBook::add(void)
{
	std::string	buf;
	Contact		contact("", "", "", "", "");

	if (_index == MAX_CONTACTS)
		_index = 0;
	if (_total != MAX_CONTACTS)
		++_total;
	if (!_contact_array[_index].getFirstName().empty())
		std::cout << "Warning: Contact " << _contact_array[_index].getFirstName()
				<< " will be replaced." << std::endl;
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

static void	displayColVal(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

static void	displayRow(const int& index, Contact contact)
{
	std::cout << "|" << std::setw(10) << index + 1;
	displayColVal(contact.getFirstName());
	displayColVal(contact.getLastName());
	displayColVal(contact.getNickName());
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayTable(void)
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < _total; ++i)
		displayRow(i, _contact_array[i]);
}

void	PhoneBook::search(void)
{
	std::string	input;
	int			index;

	if (_total < 1)
	{
		std::cout << "No contacts to search." << std::endl;
		return ;
	}
	displayTable();
	while (true)
	{
		std::cout << "Please select contact to display (1 - " <<  _total << "): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting search." << std::endl;
			std::cin.clear();
			return;
		}
		index = std::atoi(input.c_str());
		if (input.empty() || (index < 1 || index > _total))
		{
			std::cout << "Invalid option. Please enter a number between 1 and " << _total << "." << std::endl;
			continue;
        }
		std::cout << "First Name: " << _contact_array[index - 1].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contact_array[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << _contact_array[index - 1].getNickName() << std::endl;
		std::cout << "Phone Number: " << _contact_array[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contact_array[index - 1].getDarkestSecret() << std::endl;
		return ;
	}
}