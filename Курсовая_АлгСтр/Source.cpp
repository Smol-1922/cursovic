#include"reverse.h"
#include"stack.h"
#include<iostream>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	reverse_Polish_notation* ship = new reverse_Polish_notation;
	ship->call();
	ship->invert();
	std::cout << " = " << ship->result();
	std::cout << std::endl << ship->postfix_string;
	return 0;
}