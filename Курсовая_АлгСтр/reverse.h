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
	void vizov();
	void invert();
	size_t priority(char symbol);
	bool empty(size_t index);
	void virath(char operators);
	double rezultat();
private:
	stackoper operators;
	stacknumber number;
	double rezult;
	bool flag = true, flag2 = false, flag1 = true, skipspace = false;
};
#endif