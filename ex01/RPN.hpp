/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:48:46 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/04 11:35:28 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>


class RPN
{
	private:
		RPN(void);
		RPN(const RPN& rpn);
		~RPN(void);
		RPN&	operator=(const RPN& rpn);
		static void	trimSpaces(std::string& str);
		static bool isNumber(std::string& str);
		static void doOperations(std::stack<int>& stack, std::string& opt);
		static void doAddition(std::stack<int>& stack);
		static void doSubtraction(std::stack<int>& stack);
		static void doMultiplication(std::stack<int>& stack);
		static void doDivision(std::stack<int>& stack);
	public:
		static void startRPN(std::string str);
};

template<typename T>void printStack(std::stack<T> s)
{
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
}

#endif
