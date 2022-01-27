#include "phonebook.hpp"

void	Phonebook::Contact::ft_set_first_name(string first_name)
{
	this->first_name = first_name;
}

void	Phonebook::Contact::ft_set_last_name(string last_name)
{
	this->last_name = last_name;
}

void	Phonebook::Contact::ft_set_nick_name(string nick_name)
{
	this->nick_name = nick_name;
}

void	Phonebook::Contact::ft_set_phone_number(string phone_number)
{
	this->phone_number = phone_number;
}

void	Phonebook::Contact::ft_set_secret(string secret)
{
	this->darkest_secret = secret;
}

void	Phonebook::Contact::ft_printinfo(int idx, int format)
{
	if (!format)
	{
		std::cout << std::right;
		std::cout << std::setw(10) << idx << "|";
		if (this->first_name.length() <= 10)
			std::cout << std::setw(10) << this->first_name.substr(0, 10) << "|";
		else
			std::cout << this->first_name.substr(0, 9) << "." << "|";
		if (this->last_name.length() <= 10)
			std::cout << std::setw(10) << this->last_name.substr(0, 10) << "|";
		else
			std::cout << this->last_name.substr(0, 9) << "." << "|";
		if (this->nick_name.length() <= 10)
			std::cout << std::setw(10) << this->nick_name.substr(0, 10);
		else
			std::cout << this->nick_name.substr(0, 9) << ".";
		return ;
	}
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nick_name << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->darkest_secret << std::endl;
}

void	Phonebook::ft_printcontacts(void)
{
	for (unsigned int i = 0; i < idx_count && i < 8; i++)
	{
		this->contacts[i].ft_printinfo(i, 0);
		std::cout << std::endl;
	}
}

int	Phonebook::ft_gidx(void)
{
	this->idx++;
	idx_count++;
	if (idx > 8)
		idx = 1;
	return (this->idx - 1);
}