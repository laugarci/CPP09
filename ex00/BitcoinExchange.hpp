/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:52:53 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/01 14:53:40 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

class BitcoinExchange {
	private:
			
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		static void	parseLine(std::string& line);
		static void	parseValues(std::string& date, float val);
		static void searchInfo(std::string day, std::string month, std::string year, float val);
		static void printValues(std::string year, std::string month, std::string day, std::string value, float val);
		static void trimSpaces(std::string& str);
};

#endif
