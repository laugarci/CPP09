/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:04:05 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/04 13:19:03 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int checkargs(std::string str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		char c = *it;
		if (!(std::isdigit(c)) && c != '-')
		{
			std::cout << c << std::endl;
			return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "Error" << std::endl;
	else
	{
		int i = 1;
		while (av[i])
		{
			if (checkargs(av[i]))
			{
				std::cout << "Error: bad args" << std::endl;
				return (1);
			}
			i++;
		}
		try {
			PmergeMe::startPmergeMe(av[1]);
		} catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return (0);
}
