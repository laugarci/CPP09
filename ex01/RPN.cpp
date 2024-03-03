

#include "RPN.hpp"

//DEBUG
template<typename T> void printStack(std::stack<T> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void RPN::trimSpaces(std::string &str)
{
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
}

void RPN::startRPN(std::string numbers)
{
	size_t pos = 0;
	size_t pos2;
	std::stack<int> stack;

	pos2 = numbers.find(" ");
	if (pos2 == std::string::npos)
		throw std::logic_error("at least two numbers and one operator needed");
	while (pos2 != std::string::npos)
	{
		std::string next = numbers.substr(pos, pos2 - pos);
		trimSpaces(next);
		if (!next.empty())
		{
			bool isNumber = true;
			for (size_t i = 0; i < next.length(); ++i) {
				if (!isdigit(next[i])) {
					isNumber = false;
					break;
				}
			}
		if (isNumber) {
			stack.push(atoi(next.c_str()));
			}
		}
		pos = pos2 + 1;
		pos2 = numbers.find(" ", pos);
	}
	printStack(stack);
}

