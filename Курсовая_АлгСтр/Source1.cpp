#include"reverse.h"
#include<iostream>
#include<string>
reverse_Polish_notation::reverse_Polish_notation() {
	
}
void reverse_Polish_notation::vizov() {
	std::getline(std::cin,infix_string);
}
void reverse_Polish_notation::voziv() {
	std::cout << postfix_string;
}
void reverse_Polish_notation::invert() {
	int size = infix_string.length(), prioritet, prioret_stack;;
	for (int i = 0; i < size; i++) {
		if (infix_string[i] == '0' || infix_string[i] == '1'
			|| infix_string[i] == '2' || infix_string[i] == '3'
			|| infix_string[i] == '4' || infix_string[i] == '5'
			|| infix_string[i] == '6' || infix_string[i] == '7'
			|| infix_string[i] == '8' || infix_string[i] == '9') {
			std::cout << infix_string[i];
		}
		else {
			prioritet = priority(infix_string[i]);
			if (prioritet == 1) {
				operators.push(infix_string[i]);
			}
			if (prioritet == 0) {
				for (; priority(operators.head->date) != 1; operators.pop_front()) {
					if (operators.head->date == '#') {
						for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
							std::cout << operators.head->Queue.head->date;
						}
					}
					else
						std::cout << operators.head->date;
				}
				operators.pop_front();
			}
			if (prioritet == 2 || prioritet == 3 || (prioritet == 4 && flag)) {
				if (operators.head != nullptr) {
					for (; operators.head != nullptr && priority(operators.head->date) != 1 && priority(operators.head->date) >= prioritet; operators.pop_front()) {
						if (operators.head->date == '#') {
							for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
								std::cout << operators.head->Queue.head->date;
							}
						}
						else
							std::cout << operators.head->date;
					}
				}
				operators.push(infix_string[i]);
			}
			if (prioritet == 4 && !flag) {
				flag = true;
				operators.push('#');
				if (infix_string[i] == 'c') {
					if (infix_string[i + 1] == 'o') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
				}
				else if (infix_string[i] == 'l') {
					if (infix_string[i + 1] == 'o') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else {
						for (int j = i; j < i + 2; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 1;
					}
				}
				else if (infix_string[i] == 's') {
					if (infix_string[i + 1] == 'i') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else {
						for (int j = i; j < i + 4; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 3;
					}
				}
				else if (infix_string[i] == 't') {
					for (int j = i; j < i + 2; ++j)
						operators.head->Queue.push(infix_string[j]);
					i += 1;
				}
			}
		}
	}
		if (operators.size != 0) {
			for (; operators.head != nullptr; operators.pop_front()) {
				if (operators.head->date == '#') {
					for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
						std::cout << operators.head->Queue.head->date;
					}
				}
				else
					std::cout << operators.head->date;
			}
		}
}
//cos, sin, tg, ctg, ln, log, sqrt,!
int reverse_Polish_notation::priority(char symbol) {
	switch (symbol)
	{
	case '^':
	case '!':
		return 4;
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	case ')':
		return 0;
	default:
		flag = false;
		return 4;
		
	}
}