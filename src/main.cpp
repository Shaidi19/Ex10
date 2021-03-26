// Copyright 2021 Sharibzhanova Diana
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
    std::string s1 = "2 + 2";
	std::string s_postfix = infix2postfix(s1);
	std::cout << s_postfix;  
	return 0;
}
