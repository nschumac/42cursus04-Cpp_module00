#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <array>
#include <iomanip>

using std::string;

class Phonebook
{
	private:
		class Contact
		{
			private:
				string first_name;
				string last_name;
				string nick_name;
				string phone_number;
				string darkest_secret;
			public:
				void	ft_set_first_name(string first_name);
				void	ft_set_last_name(string last_name);
				void	ft_set_nick_name(string nick_name);
				void	ft_set_phone_number(string phone_number);
				void	ft_set_secret(string secret);
				void	ft_printinfo(int idx, int winfo);
		};

		unsigned int	idx; // Index of where to write
	
	public:
		unsigned int	idx_count;
		std::array<Contact, 8>contacts;

		int	ft_gidx(void); // Returns index

		void	ft_printcontacts(void);
};
