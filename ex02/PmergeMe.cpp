/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:12 by laugarci          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/08 14:23:46 by laugarci         ###   ########.fr       */
=======
/*   Updated: 2024/03/08 14:18:32 by laugarci         ###   ########.fr       */
>>>>>>> 5340c5fcb74649bf5886c261503b5e70ddfd4fd9
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

void PmergeMe::trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

void PmergeMe::printTime(clock_t end, clock_t start, std::string type, int size)
{
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << size << " elements with std::"<< type << " : " << std::fixed << time_taken << std::setprecision(5);
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
		}
		else
		{
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

    return (result);
}

std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return arr;
	int mid = arr.size() / 2;
	print(arr);
	std::vector<int> left(arr.begin(), arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.end());
	
	left = fordJohnsonSortVector(left);
	right = fordJohnsonSortVector(right);
	return (mergeVector(left, right));
}

std::deque<int> PmergeMe::mergeDeque(const std::deque<int>& left, const std::deque<int>& right) {
        std::deque<int> result;
        unsigned int leftIndex = 0, rightIndex = 0;

        while (leftIndex < left.size() && rightIndex < right.size()) {
            if (left[leftIndex] < right[rightIndex]) {
                result.push_back(left[leftIndex]);
                leftIndex++;
            } else {
                result.push_back(right[rightIndex]);
                rightIndex++;
            }
        }

        while (leftIndex < left.size()) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        }

        while (rightIndex < right.size()) {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }

        return result;
    }

std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
        if (arr.size() <= 1)
            return arr;
        int mid = arr.size() / 2;
        std::deque<int> left(arr.begin(), arr.begin() + mid);
        std::deque<int> right(arr.begin() + mid, arr.end());

        left = fordJohnsonSortDeque(left);
        right = fordJohnsonSortDeque(right);
        return mergeDeque(left, right);
    }

void	PmergeMe::startPmergeMe(std::string nums)
{
	std::vector<int> vector;
	std::deque<int> deque;
	clock_t end, start;
	trimSpaces(nums);
	addToContainer(nums, vector);
	addToContainer(nums, deque);
	std::cout << "Before: ";
	print(vector);
	start = clock();
	vector = fordJohnsonSortVector(vector);
	end = clock();
	std::cout << "After: ";
	print (vector);
	printTime(end, start, "vector", vector.size());
	start = clock();
	deque = fordJohnsonSortDeque(deque);
	end = clock();
	printTime(end, start,"deque", deque.size());
}
