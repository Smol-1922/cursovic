#ifndef reverse_H
#define reverse_H
#include<string>
#include"stack.h"
class reverse_Polish_notation
{
public:
	reverse_Polish_notation();
	~reverse_Polish_notation();
	void vizov();
	void voziv();
	void invert();
	int priority(char symbol);
private:
	stack operators;
	std::string postfix_string;
	std::string infix_string;
	stack number;
	bool flag,flag1=false;
};
#endif