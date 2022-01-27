#include <iostream>
#include <string>

std::string	ft_toupper(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int c = 1; c < argc; c++)
			std::cout << ft_toupper(argv[c]);
		std::cout << std::endl;
	}
	return (0);
}