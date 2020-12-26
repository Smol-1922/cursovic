#ifndef reverse_H
#define reverse_H
#include<string>
#include"stack.h"
#include"stacknumber.h"
class reverse_Polish_notation
{
public:
	reverse_Polish_notation();
	~reverse_Polish_notation();
	void vizov();
	void voziv();
	void invert();
	int priority(char symbol);
	bool empty(int index);
	void virath(char operators);
private:
	stackoper operators;
	std::string postfix_string;
	std::string infix_string;
	stacknumber number;
	bool flag = true, flag1 = true, skipspace = false;
};
#endif