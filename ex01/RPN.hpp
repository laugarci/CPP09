
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
	public:
		static void startRPN(std::string str);
};

#endif
