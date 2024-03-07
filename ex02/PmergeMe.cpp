/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:12 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/07 15:58:33 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

void PmergeMe::printTime(clock_t end, clock_t start, int size)
{
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << size << " elements with std::deque : " << std::fixed << time_taken << std::setprecision(5);
	std::cout << " us " << std::endl;
}

std::vector<int> PmergeMe::mergeVector(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> result;
	unsigned int leftIndex = 0, rightIndex = 0;
	
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex] < right[rightIndex])
		{
			result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    while (leftIndex < left.size())
	{
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    while (rightIndex < right.size())
	{
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return arr;
    int mid = arr.size() / 2;
	std::vector<int> left(arr.begin(), arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.end());

    left = fordJohnsonSortVector(left);
    right = fordJohnsonSortVector(right);

    return mergeVector(left, right);
}

void	PmergeMe::startPmergeMe(std::string nums)
{
	std::vector<int> vector;
	trimSpaces(nums);
	addToContainer(nums, vector);
	std::cout << "Before: ";
	print(vector);
	vector = fordJohnsonSortVector(vector);
	std::cout << "After: ";
	print(vector);
}
