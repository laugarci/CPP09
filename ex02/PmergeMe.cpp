/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:12 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/05 16:46:54 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
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
	std::cout << "After:  ";
	print(A);
	clock_t end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << A.size() << "with std::vector : " << std::fixed
         << time_taken << std::setprecision(5);
	std::cout << " us " << std::endl;
}

 void PmergeMe::fordJohnsonDeque(std::deque<int>& A) {
        clock_t start = clock();
        std::deque<int> B, C;
        while (!A.empty()) {
            int minIdx = minIndex(A);
            int maxIdx = maxIndex(A);
            if (A[minIdx] < A[maxIdx]) {
                B.push_back(A[minIdx]);
                A.erase(A.begin() + minIdx);
            } else {
                C.push_front(A[maxIdx]);
                A.erase(A.begin() + maxIdx);
            }
        }
        A = B;
        A.insert(A.end(), C.begin(), C.end());
        clock_t end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << A.size() << "with std::deque : " << std::fixed
                  << time_taken << std::setprecision(5);
        std::cout << " us " << std::endl;
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
	std::deque<int> deque;
	trimSpaces(nums);
	addToContainer(nums, vector);
	addToContainer(nums, deque);
	std::cout << "Before: ";
	print(vector);
	fordJohnsonVector(vector);
	fordJohnsonDeque(deque);
}
