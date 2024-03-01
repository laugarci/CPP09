/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:52:44 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/01 13:33:29 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
	return(*this);
	(void)other;
}

void	BitcoinExchange::parseDate(std::string& date)
{
	std::string str;
	size_t pos = date.find("-");
	size_t pos2 = date.find("-", pos);

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			str = date.substr(0, pos);
			if (std::stoi(str) > 2022 || std::stoi(str) < 2009)
			{
				std::cout << "fecha incorrecta" << std::endl;
				throw std::exception();
			}
		}
		else
		{
			pos = date.find("-", pos);
			pos2 = date.find("-", pos);
			str = date.substr(pos + 1, pos2 - 2);
			if (i == 1 && (std::stoi(str) > 12 || std::stoi(str) < 1))
			{
				std::cout << "mes incorrecto" << std::endl;
				throw std::exception();
			}
			if (i == 2 && (std::stoi(str) > 31 || std::stoi(str) < 1))
			{
				std::cout << "dia incorrecto" << std::endl;
				throw std::exception();
			}
			pos++;
		}
	}
}

void	BitcoinExchange::parseLine(std::string& line)
{
	size_t pos;
	std::string date;
	int val;

	pos = line.find("|");
	if (pos == std::string::npos)
		throw std::exception();
	date = line.substr(0, pos);
	val = std::stoi(line.substr(pos + 1, '\n'));
	BitcoinExchange::parseDate(date);
}
