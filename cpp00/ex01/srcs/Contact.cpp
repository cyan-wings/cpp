#include "Contact.hpp"

Contact::Contact() : _firstname(""), _lastname(""), _nickname(""), _phonenumber(""), _darkestsecret("") {}

Contact::Contact
(
	const std::string& firstname,
	const std::string& lastname,
	const std::string& nickname,
	const std::string& phonenumber,
	const std::string& darkestsecret
):
	_firstname(firstname),
	_lastname(lastname),
	_nickname(nickname),
	_phonenumber(phonenumber),
	_darkestsecret(darkestsecret) {}

Contact::~Contact(void) {}

const std::string&	Contact::getFirstName(void) const {return _firstname;}

const std::string&	Contact::getLastName(void) const {return _lastname;}

const std::string&	Contact::getNickName(void) const {return _nickname;}

const std::string&	Contact::getPhoneNumber(void) const {return _phonenumber;}

const std::string&	Contact::getDarkestSecret(void) const { return _darkestsecret;}

void				Contact::setFirstName(const std::string& firstname) {_firstname = firstname;}

void				Contact::setLastName(const std::string& lastname) {_lastname = lastname;}

void				Contact::setNickName(const std::string& nickname) {_nickname = nickname;}

void				Contact::setPhoneNumber(const std::string& phonenumber) {_phonenumber = phonenumber;}

void				Contact::setDarkestSecret(const std::string& darkestsecret) {_darkestsecret = darkestsecret;}
