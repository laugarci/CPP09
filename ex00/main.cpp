/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:38:44 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/01 18:16:27 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string readFromFile(const std::string& filename)
{
	std::ifstream file(filename);
	std::string content; 
	std::string line;
	
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			try{
				BitcoinExchange::parseLine(line);
			}
			catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			content += line;
			content += '\n';
		}
		file.close();
	}
	else
		std::cerr << "Error: could not open file " << filename << std::endl;
	return (content); 
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Incorrect args" << std::endl;
		return (1);
	}
	std::string inputContent = readFromFile(av[1]);
    return (0);
}

