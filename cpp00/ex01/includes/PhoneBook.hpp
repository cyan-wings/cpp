#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		static const int	MAX_CONTACTS = 3;
		Contact				_contact_array[MAX_CONTACTS];
		int					_index;
		int					_total;
		void				displayTable(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif
