/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:50 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/04 17:33:36 by laugarci         ###   ########.fr       */
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
		static void trimSpaces(std::string& str);
		static void	addToVector(std::string numbers, std::vector<int>& vector);
		static void	fordJohnsonVector(std::vector<int>& A);
//		static int minIndex(std::vector<int>& vec);
//		static int maxIndex(std::vector<int>& vec);
	public:
		static void	startPmergeMe(std::string nums);

};

template<typename T> void printVector(const std::vector<T>& vec)
{
    typename std::vector<T>::const_iterator it = vec.begin();
    std::cout << "[";
    if (it != vec.end()) {
        std::cout << *it;
        ++it;
    }
    for (; it != vec.end(); ++it) {
        std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
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

