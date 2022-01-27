#include "phonebook.hpp"

void	ft_addcontact(Phonebook &c_phonebook)
{
	int idx;
	string	buf;

	idx = c_phonebook.ft_gidx();
	if (idx >= 8)
		idx = 7;
	std::cout << "First Name: ";
	std::getline(std::cin, buf);
	c_phonebook.contacts[idx].ft_set_first_name(buf);
	std::cout << "Last Name: ";
	std::getline(std::cin, buf);
	c_phonebook.contacts[idx].ft_set_last_name(buf);
	std::cout << "Nick Name: ";
	std::getline(std::cin, buf);
	c_phonebook.contacts[idx].ft_set_nick_name(buf);
	std::cout << "Phone Number: ";
	std::getline(std::cin, buf);
	c_phonebook.contacts[idx].ft_set_phone_number(buf);
	std::cout << "Dark Secret: ";
	std::getline(std::cin, buf);
	c_phonebook.contacts[idx].ft_set_secret(buf);
}

void	ft_searchcontact(Phonebook &c_phonebook)
{
	string			command;
	unsigned int	idx;

	c_phonebook.ft_printcontacts();
	std::cout << "Index: ";
	std::getline(std::cin, command);
	if (command.length() > 1 || command[0] < '0' || command[0] > '7')
		std::cout << "Invalid Index!" << std::endl;
	else
	{
		idx = atoi(command.c_str());
		if (idx >= c_phonebook.idx_count)
			std::cout << "Invalid Index!"<< std::endl;
		else
			c_phonebook.contacts[idx].ft_printinfo(idx, 1);
	}
}

void	ft_mainloop(Phonebook &c_phonebook)
{
	string	command;

	do
	{
		command = "";
		std::cout << "pb> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			ft_addcontact(c_phonebook);
		else if (command == "SEARCH")
			ft_searchcontact(c_phonebook);
	} while (command != "EXIT");
}

int main(void)
{
	Phonebook c_phonebook;

	ft_mainloop(c_phonebook);
	return (0);
}


