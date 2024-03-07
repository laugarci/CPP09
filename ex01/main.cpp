

#include "RPN.hpp"

int	checkNums(std::string str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		char c = *it;
		if (!(std::isdigit(c) || std::isspace(c) || c == '+' || c == '-' || c == '*' || c == '/'))
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "args error" << std::endl;
	else
	{
		if (checkNums(av[1]))
			std::cout << "Error" << std::endl;
		else
		{
			try {
				RPN::startRPN(av[1]);
			} catch (std::exception& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
	return (0);
}
