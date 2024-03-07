/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:38:44 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/07 12:09:04 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void readFromFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	
	if (file.is_open())
	{
		std::getline(file, line);
		if (line.compare("date | value") != 0)
		{
			std::cout << "Error: bad format => " << line << " is not 'date | value'"  << std::endl;
			return ;
		}
		while (std::getline(file, line))
		{
			try{
				BitcoinExchange::parseLine(line);
			}
			catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
		file.close();
	}
	else
		std::cerr << "Error: could not open file " << filename << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	readFromFile(av[1]);
    return (0);
}

