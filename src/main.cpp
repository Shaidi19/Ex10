// Copyright 2021 Sharibzhanova Diana
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
	std::string s1 = "7-2*3";
	std::string s_postfix = infix2postfix(s1);
	std::cout << s_postfix;  //  723*-
	return 0;
}
