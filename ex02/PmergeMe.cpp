/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:12 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/04 16:52:01 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

int PmergeMe::minIndex(std::vector<int>& vec)
{
    int minVal;
    int minIdx = -1;
    for (size_t i = 0; i < vec.size(); ++i)
	{
        if (vec[i] < minVal)
		{
            minVal = vec[i];
            minIdx = i;
        }
    }
    return (minIdx);
}

int PmergeMe::maxIndex(std::vector<int>& vec) 
{
    int maxVal;
    int maxIdx = -1;
    for (size_t i = 0; i < vec.size(); ++i)
	{
        if (vec[i] > maxVal) {
            maxVal = vec[i];
            maxIdx = i;
        }
    }
    return (maxIdx);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& A)
{
	clock_t start = clock();
	std::vector<int> B, C;
    while (!A.empty())
	{
        int minIdx = minIndex(A);
        int maxIdx = maxIndex(A);
        if (A[minIdx] < A[maxIdx])
		{
            B.push_back(A[minIdx]);
            A.erase(A.begin() + minIdx);
		}
		else
		{
            C.insert(C.begin(), A[maxIdx]);
            A.erase(A.begin() + maxIdx);
        }
    }
    reverse(C.begin(), C.end());
    A = B;
    A.insert(A.end(), C.begin(), C.end());
	std::cout << "After: ";
	printVector(A);
	clock_t end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time taken by program is : " << std::fixed
         << time_taken << std::setprecision(5);
	std::cout << " sec " << std::endl;
}

void PmergeMe::addToVector(std::string numbers, std::vector<int>& vector)
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
        trimSpaces(next);
        if (!next.empty())
            vector.push_back(std::stoi(next));
        pos = pos2 + 1;
        pos2 = numbers.find(" ", pos);
    }
    next = numbers.substr(pos);
    if (!next.empty())
        vector.push_back(std::stoi(next));
}

void	PmergeMe::startPmergeMe(std::string nums)
{
	std::vector<int> vector;
	trimSpaces(nums);
	addToVector(nums, vector);
	fordJohnsonVector(vector);
}
