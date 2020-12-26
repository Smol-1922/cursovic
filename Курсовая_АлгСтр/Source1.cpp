#include"reverse.h"
#include<iostream>
#include<string>
#include <cmath>
#include <sstream>
#define _USE_MATH_DEFINES
reverse_Polish_notation::reverse_Polish_notation() {
	
}
void reverse_Polish_notation::vizov() {
	std::getline(std::cin,infix_string);
}
void reverse_Polish_notation::voziv() {
	std::cout << postfix_string;
}
double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}
void reverse_Polish_notation::invert() {
	int size = infix_string.length(), prioritet, prioret_stack;;
	for (int i = 0; i < size; i++) {
		if (infix_string[i] == '0' || infix_string[i] == '1'
			|| infix_string[i] == '2' || infix_string[i] == '3'
			|| infix_string[i] == '4' || infix_string[i] == '5'
			|| infix_string[i] == '6' || infix_string[i] == '7'
			|| infix_string[i] == '8' || infix_string[i] == '9' || infix_string[i] == '.') {
			std::cout << infix_string[i];
			if (flag1) {
				flag1 = false;
				number.push(0);
			}
			number.head->numb += infix_string[i];
			number.head->date = atof(number.head->numb.c_str());
		}
		else if (infix_string[i] == 'p' && empty(i)) {
			std::cout << infix_string[i];
			if (infix_string[i + 1] == 'i') {
				std::cout << infix_string[i+1];
				number.push(acos(-1.0));
				i++;
			}
			else
			{
				std::cout << "ошибка ввода";
				return;
			}
		}
		else if (infix_string[i] == 'e' && empty(i)){
			std::cout << infix_string[i];
			number.push(exp(1));
			}
		else {
			if (!flag1) {
				flag1 = true;
			}
			std::cout << " ";
			prioritet = priority(infix_string[i]);
			if (prioritet == 1) {
				operators.push(infix_string[i]);
			}
			else if (prioritet == 0) {
				for (; priority(operators.head->date) != 1; operators.pop_front()) {
					if (operators.head->date == '#') {
						virath(operators.head->date);
						for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
							std::cout << operators.head->Queue.head->date;
						}

					}
					else {
						virath(operators.head->date);
						std::cout << operators.head->date;
					}
				}
				operators.pop_front();
			}
			else if (prioritet == 2 || prioritet == 3 || (prioritet == 4 && flag)) {
				if (operators.head != nullptr) {
					for (; operators.head != nullptr && priority(operators.head->date) != 1 && priority(operators.head->date) >= prioritet; operators.pop_front()) {
						if (operators.head->date == '#') {
							virath(operators.head->date);
							for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
								std::cout << operators.head->Queue.head->date;
							}
						}
						else {
							virath(operators.head->date);
							std::cout << operators.head->date;
						}
					}
				}
				operators.push(infix_string[i]);
			}
			else if (prioritet == 4 && !flag) {
				flag = true;
				operators.push('#');
				if (infix_string[i] == 'c' && empty(i)) {
					if (empty(i + 1) && empty(i + 2)) {
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
					else
					{
						std::cout << "ошибка ввода";
						return;
					}
				}
				else if (infix_string[i] == 'l') {
					if (empty(i + 1)) {
						if (infix_string[i + 1] == 'o' && empty(i + 2)) {
							for (int j = i; j < i + 3; ++j)
								operators.head->Queue.push(infix_string[j]);
							i += 2;
						}
						else if (empty(i + 1)) {

							for (int j = i; j < i + 2; ++j)
								operators.head->Queue.push(infix_string[j]);
							i += 1;
						}
					}
					else
					{
						std::cout << "ошибка ввода";
						return;
					}
				}
				else if (infix_string[i] == 's') {
					if (empty(i + 1) && empty(i + 2)) {
						if (infix_string[i + 1] == 'i') {
							for (int j = i; j < i + 3; ++j)
								operators.head->Queue.push(infix_string[j]);
							i += 2;
						}
						else if(empty(i + 3)) {
							for (int j = i; j < i + 4; ++j)
								operators.head->Queue.push(infix_string[j]);
							i += 3;
						}
					}
					else
					{
						std::cout << "ошибка ввода";
						return;
					}
				}
				else if (infix_string[i] == 't') {
					if (empty(i + 1)) {
						for (int j = i; j < i + 2; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 1;
					}
					else
					{
						std::cout << "ошибка ввода";
						return;
					}
				}

			}
			else
			{
			std::cout << "ошибка ввода";
			return;
			}
		}
	}

	if (operators.size != 0) {
		for (; operators.head != nullptr; operators.pop_front()) {
			if (operators.head->date == '#') {
				virath(operators.head->date);
				for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
					std::cout << operators.head->Queue.head->date;
				}
				
			}
			else {
				virath(operators.head->date);
				std::cout << operators.head->date;
			}
		}
	}
	std::cout <<" = "<<number.head->date;
}
// ctg,!
int reverse_Polish_notation::priority(char symbol) {
	switch (symbol)
	{
	case '^':
	case '!':
	case'#':
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
bool reverse_Polish_notation::empty(int index) {
	if (infix_string.length() >= index + 1) {
		return 1;
	}
	return 0;
}
void reverse_Polish_notation::virath(char operato) {
	double shtoto;
	switch (operato)
	{
	case '^': {
		shtoto = pow(number.head->next->date, number.head->date);
		number.pop_front();
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '!':
	{
		shtoto = number.head->date;
		if (0 < shtoto < 1) {
			shtoto = sqrt(2 * 3.1415 * number.head->date) * pow((number.head->date / 2.7182), number.head->date);
			number.pop_front();
			number.push(shtoto);
			return;
		}
		shtoto = fact(number.head->date);
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '*':
	{
		shtoto = number.head->next->date * number.head->date;
		number.pop_front();
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '/':
	{
		shtoto = number.head->next->date / number.head->date;
		number.pop_front();
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '-':
	{
		shtoto = number.head->next->date - number.head->date;
		number.pop_front();
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '+':
	{
		shtoto = number.head->next->date + number.head->date;
		number.pop_front();
		number.pop_front();
		number.push(shtoto);
		break;
	}
	case '#': 
	{
		if (operators.head->Queue.head->date == 'c') {
				if (operators.head->Queue.head->next->date == 'o') {
					shtoto = cos(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
				else {
					shtoto = 1/tan(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
		}
		else if (operators.head->Queue.head->date == 'l') {
				if (operators.head->Queue.head->next->date == 'o') {
					shtoto = log10(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
				else  {
					shtoto = log(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
		}
		else if (operators.head->Queue.head->date == 's') {
				if (operators.head->Queue.head->next->date == 'i') {
					shtoto = sin(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
				else  {
					shtoto = sqrt(number.head->date);
					number.pop_front();
					number.push(shtoto);
				}
		}
		else if (operators.head->Queue.head->date == 't') {
			shtoto = tan(number.head->date);
			number.pop_front();
			number.push(shtoto);
		}

	}
	default:
		break;
	}
}
