#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

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
	else
		++_total;
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
	std::cout << "|" << std::setw(10) << index;
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
	int	input;

	displayTable();
	while (true)
	{
		std::cout << "Please select contact to display (0 - " <<  _total - 1 << "): ";
		if (!(std::cin >> input))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
			continue;
		}
		if (input >= 0 && input < _total)
		{
			std::cout << "First Name: " << _contact_array[input].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contact_array[input].getLastName() << std::endl;
			std::cout << "Nickname: " << _contact_array[input].getNickName() << std::endl;
			std::cout << "Phone Number: " << _contact_array[input].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contact_array[input].getDarkestSecret() << std::endl;
			return ;
		}
		std::cout << "Invalid option." << std::endl;
	}
}