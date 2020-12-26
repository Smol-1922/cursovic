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
	void invert();
	int priority(char symbol);
	bool empty(int index);
	void virath(char operators);
private:
	stackoper operators;
	std::string infix_string;
	stacknumber number;
	bool flag = true, flag2 = false, flag1 = true, skipspace = false;
};
#endif