/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:52:44 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/01 18:11:23 by laugarci         ###   ########.fr       */
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

void BitcoinExchange::trimSpaces(std::string &str)
{
    std::string::size_type start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        ++start;
    }

    std::string::size_type end = str.length();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    str = str.substr(start, end - start);
}

void	BitcoinExchange::printValues(std::string year, std::string month, std::string day, std::string value, float val)
{	
	std::cout << year << "-" << month << "-"<< day << " => " << val << " = " << std::stof(value) * val << std::endl;	
}

std::string BitcoinExchange::searchInfo(std::string day, std::string month, std::string year)
{
	std::string line;
	std::ifstream file("data.csv");
	std::string sub;
	std::string value = "";

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			sub = line.substr(0, line.find(","));
			if (sub.find(year) != std::string::npos && sub.find(month, 4) != std::string::npos && sub.find(day, 7) != std::string::npos)
			{
				value = line.substr(line.find(",") + 1);
				break ;
			}
		}
	}
	else
		throw std::runtime_error("impossible to open.");
	return (value);
}

std::string BitcoinExchange::recursiveInfo(std::string day, std::string month, std::string year)
{
	std::string data = "";

	while (data.empty())
	{
		int d = std::stoi(day);
		while (d > 1)
		{
			d -= 1;
			day = std::to_string(d);
			if (d < 10)
				day = "0" + day;
			data = searchInfo(day, month, year);
			if (!data.empty())
				return (data);
		}
		int m = std::stoi(month);
		m -= 1;
		while (m > 1)
		{
			d = 31;
			while (d > 1)
			{
				day = std::to_string(d);
				month = std::to_string(m);
				data = searchInfo(day, month, year);
				if (!data.empty())
						return (data);
				d -= 1;
			}
			m -= 1;
		}
		int y = std::stoi(year);
		y -= 1;
		while (y > 2009)
		{
			d = 31;
			m = 12;
			while (m > 1)
			{
				d = 31;
				while (d > 1)
				{
					day = std::to_string(d);
					month = std::to_string(m);
					year = std::to_string(y);
					data = searchInfo(day, month, year);
					if (!data.empty())
						return (data);
					d -= 1;
				}
				m -= 1;
			}
			y -= 1;
		}
	}
	return (data);
}

void	BitcoinExchange::parseValues(std::string& date, float val)
{
	std::string str;
	size_t pos = date.find("-");
	size_t pos2 = date.find("-", pos);
	std::string month, day, year;

	if (pos == std::string::npos || pos2 == std::string::npos)
		throw std::runtime_error("bad format.");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			trimSpaces(str = date.substr(0, pos));
			if (str.empty())
				throw std::runtime_error("bad format.");
			if (std::stoi(str) > 2022 || std::stoi(str) < 2009)
				throw std::runtime_error("impossible found");
			year = str;
		}
		else
		{
			pos = date.find("-", pos);
			pos2 = date.find("-", pos);
			if (pos == std::string::npos || pos2 == std::string::npos)
				throw std::runtime_error("bad format");
			trimSpaces(str = date.substr(pos + 1, pos2 - 2));
			if (str.empty())
				throw std::runtime_error("bad format");
			if (i == 1)
			{
				month = str;
				if (std::stoi(month) > 12 || std::stoi(month) < 1)
					throw std::runtime_error("not a positive number or inexistent month");
			}
			if (i == 2)
			{
				day = str;
				if ((std::stoi(day) > 31 || std::stoi(day) < 1) || (std::stoi(month) == 2 && std::stoi(day) > 29))
					throw std::runtime_error("not a positive number or inexistend day");
			}
			pos++;
		}
	}
	if (val < 0)
		throw std::runtime_error("not a positive number");
	std::string data = searchInfo(day, month, year);
	if (data.empty())
		data = recursiveInfo(day, month, year);
	printValues(year, month, day, data, val);
}

void	BitcoinExchange::parseLine(std::string& line)
{
	size_t pos;
	std::string date;
	float val;

	pos = line.find("|");
	if (pos == std::string::npos)
		throw std::runtime_error("bad input => " + line);
	date = line.substr(0, pos);
	std::string value = line.substr(pos + 1, '\n');
	if (std::atoi(value.c_str()) > 1000)
		throw std::runtime_error("too large a number.");
	if (value.empty())
		throw std::runtime_error("empty information");
	val = std::stof(value);
	BitcoinExchange::parseValues(date, val);
}
