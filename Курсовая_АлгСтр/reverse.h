#ifndef reverse_H
#define reverse_H
#include<string>
#include"stack.h"
#include"stacknumber.h"
class reverse_Polish_notation
{
public:
	std::string infix_string;
	std::string postfix_string;
	reverse_Polish_notation();
	~reverse_Polish_notation();
	void call();
	void invert();
	size_t priority(char symbol);
	bool empty(size_t index);
	void realization(char operators);
	double result();
private:
	stackoper operators;
	stacknumber number;
	double rezult;
	bool flag = true, now = true, skipspace = false;
};
#endif