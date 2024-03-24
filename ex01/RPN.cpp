/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:48:48 by laugarci          #+#    #+#             */
/*   Updated: 2024/03/08 14:21:15 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& rpn)
{
	(void)rpn;
}

RPN::~RPN(void)
{
}

RPN&	RPN::operator=(const RPN& rpn)
{
	(void)rpn;
	return (*this);
}

void RPN::trimSpaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

bool RPN::isNumber(std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	if ((str[i] == '-' || str[i] == '+') && std::isdigit(str[i + 1]))
	{
		++i;
		if (i == str.size())
			throw std::logic_error("not a valid number");
	}
	for (; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
				throw std::logic_error("not a valid number");
			else
				return false;
		}
	}
	return true;
}

void	RPN::doAddition(std::stack<int>& stack)
{	
	int num1;
	int num2;

	if (stack.size() >= 2)
	{
		num1 = stack.top();
		stack.pop();
		num2 = stack.top();
		stack.pop();
		stack.push(num2 + num1);
	}
	else
		throw std::logic_error("logic error");
}

void	RPN::doSubtraction(std::stack<int>& stack)
{
	int num1;
	int num2;

	if (stack.size() >= 2)
	{
		num1 = stack.top();
		stack.pop();
		num2 = stack.top();
		stack.pop();
		stack.push(num2 - num1);
	}
	else
		throw std::logic_error("logic error");
}

void	RPN::doMultiplication(std::stack<int>& stack)
{
	int num1;
	int num2;

	if (stack.size() >= 2)
	{
		num1 = stack.top();
		stack.pop();
		num2 = stack.top();
		stack.pop();
		stack.push(num2 * num1);
	}
	else
		throw std::logic_error("logic error");
}

void	RPN::doDivision(std::stack<int>& stack)
{
	int num1;
	int num2;

	if (stack.size() >= 2)
	{
		num1 = stack.top();
		stack.pop();
		num2 = stack.top();
		if (num1 == 0)
			throw std::logic_error("the operation cannot be done.");
		stack.pop();
		stack.push(num2 / num1);
	}
	else
		throw std::logic_error("logic error");
}

void	RPN::doOperations(std::stack<int>& stack, std::string& opt)
{
	if (!opt.compare("+"))
		doAddition(stack);
	else if (!opt.compare("-"))
		doSubtraction(stack);
	else if (!opt.compare("*"))
		doMultiplication(stack);
	else if (!opt.compare("/"))
		doDivision(stack);
}

void RPN::startRPN(std::string numbers)
{
	size_t pos = 0;
	size_t pos2;
	std::stack<int> stack;
	std::string next;

	trimSpaces(numbers);
	pos2 = numbers.find(" ");
	if (pos2 == std::string::npos)
		throw std::logic_error("at least two numbers and one operator needed");
	while (pos2 != std::string::npos)
	{
		next = numbers.substr(pos, pos2 - pos);
		trimSpaces(next);
		if (!next.empty())
		{
			if (isNumber(next))
				stack.push(std::atoi(next.c_str()));
			else
				doOperations(stack, next);
		}
		pos = pos2 + 1;
		pos2 = numbers.find(" ", pos);
		if (pos2 == std::string::npos)
		{
			next = numbers.substr(pos);
			if (!next.empty())
			{
				if (isNumber(next))
					stack.push(std::atoi(next.c_str()));
				else
					doOperations(stack, next);
			}
		}
	}
	if (stack.size() > 1)
		throw std::logic_error("logic error");
	printStack(stack);
}
