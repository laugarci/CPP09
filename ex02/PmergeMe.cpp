/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:12 by laugarci          #+#    #+#             */
/*   Updated: 2024/04/16 14:51:44 by laugarci         ###   ########.fr       */
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

std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return arr;
	return (fibonacciSort(arr));
}

bool compare(const int& a, const int& b)
{
	return (a < b);
}

void sortInPairs(std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
    }
}

std::vector<int>& PmergeMe::fibonacciSort(std::vector<int>& arr)
{
	int n = arr.size();
	std::vector<int> fibonacci;

	fibonacci.push_back(1);
	fibonacci.push_back(1);
	int fib = 1;
	while (fib < n)
	{
		fib = fibonacci[fibonacci.size() - 1] + 2 * fibonacci[fibonacci.size() - 2];
		fibonacci.push_back(fib);
	}

	int index = fibonacci.size() - 3;
	while (index >= 0)
	{
		int step = fibonacci[index];
		for (int i = step; i < n; ++i)
		{
			int temp = arr[i];
			int j = i;
			while (j >= step && arr[j - step] > temp)
			{
				arr[j] = arr[j - step];
				j -= step;
			}
			arr[j] = temp;
		}
		--index;
	}
	return (arr);
}

void sortInPairs(std::deque<int>& arr)
{
	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
	}
}

std::deque<int>& PmergeMe::fibonacciSortDeque(std::deque<int>& arr)
{
	int n = arr.size();
	std::deque<int> fibonacci;
	
	fibonacci.push_back(1);
	fibonacci.push_back(1);
	int fib = 1;
	while (fib < n)
	{
		fib = fibonacci[fibonacci.size() - 1] + 2 * fibonacci[fibonacci.size() - 2];
		fibonacci.push_back(fib);
	}
	
	int index = fibonacci.size() - 3;
	while (index >= 0)
	{
		int step = fibonacci[index];
		for (int i = step; i < n; ++i)
		{
			int temp = arr[i];
			int j = i;
			while (j >= step && arr[j - step] > temp)
			{
				arr[j] = arr[j - step];
				j -= step;
			}
			arr[j] = temp;
		}
		--index;
	}
	return (arr);
}

std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return arr;
	return fibonacciSortDeque(arr);
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
