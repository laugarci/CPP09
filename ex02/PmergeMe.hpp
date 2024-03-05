/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:50 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/05 16:45:18 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
	private:
		static const unsigned int	_size = 5;
		PmergeMe( void );
		PmergeMe( const PmergeMe& pmm );
		~PmergeMe( void );
		PmergeMe&			operator=(const PmergeMe& pmm);
		static void	addToVector(std::string numbers, std::vector<int>& vector);
		static void	fordJohnsonVector(std::vector<int>& A);
		static void fordJohnsonDeque(std::deque<int>& A);
	public:
		static void trimSpaces(std::string& str);
		static void	startPmergeMe(std::string nums);

};

template <typename Container> void print(const Container& cont)
{
    typename Container::const_iterator it; 
	std::cout << "[ ";
    for (it = cont.begin(); it != cont.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << "]";
    std::cout << std::endl;
}

template<typename T> int minIndex(const T& cont)
{
    typename T::const_iterator minIt = std::min_element(cont.begin(), cont.end());
    return std::distance(cont.begin(), minIt);
}

template<typename T> int maxIndex(const T& cont)
{
    typename T::const_iterator maxIt = std::max_element(cont.begin(), cont.end());
    return std::distance(cont.begin(), maxIt);
}

template <typename Container> void addToContainer(std::string numbers, Container& container)
{
	size_t pos = 0;
	size_t pos2;
	std::string next;
	
	pos2 = numbers.find(" ");
	if (pos2 == std::string::npos)
		throw std::logic_error("at least two numbers separated by spaces are needed");
	while (pos2 != std::string::npos)
	{
		next = numbers.substr(pos, pos2 - pos);
		PmergeMe::trimSpaces(next);
		if (!next.empty())
			container.push_back(std::stoi(next));
		pos = pos2 + 1;
		pos2 = numbers.find(" ", pos);
	}
	next = numbers.substr(pos);
	if (!next.empty())
		container.push_back(std::stoi(next));
}
