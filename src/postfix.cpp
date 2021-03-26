// Copyright 2021 Sharibzhanova Diana
#include <iostream>
#include <string>
#include "MyStack.h"
#include "postfix.h"

int priority_level(char a) {
  int ascii = (unsigned char)a;
  if (ascii == 41)
    return 1;
  else if (ascii == 43 || ascii == 45)
    return 2;
  else if (ascii == 42 || ascii == 47)
    return 3;
}

std::string infix2postfix(std::string infix) {
  std::string str;
  MyStack<char> stack(infix.size());
  for (int i = 0; i < infix.size(); i++) {
    if ((unsigned char)infix[i] == 32) continue;
    if ((unsigned char)infix[i] >= 48 && (unsigned char)infix[i] <= 57) {
      str.push_back(infix[i]);
      str.push_back(' ');
    } else if ((unsigned char)infix[i] == 46) {
      str.pop_back();
      str.push_back(infix[i]);
      str.push_back(infix[i]);
      str.push_back(' ');
    } else if ((unsigned char)infix[i] == 40) {
      stack.push(infix[i]);
    } else if ((unsigned char)infix[i] == 41) {
      while ((unsigned char)stack.get() != 40) {
        str.push_back(stack.pop());
        str.push_back(' ');
      }
      stack.pop();
    } else if (stack.isEmpty() ||
               priority_level(stack.get()) < priority_level(infix[i])) {
      stack.push(infix[i]);
    } else if (priority_level(stack.get()) >= priority_level(infix[i])) {
      
        while (!stack.isEmpty() &&
             priority_level(stack.get()) >= priority_level(infix[i])) {
        str.push_back(stack.pop());
        str.push_back(' ');
      }
      stack.push(infix[i]);
    }
  }
  while (!stack.isEmpty()) {
    str.push_back(stack.pop());
    str.push_back(' ');
  }
  str.pop_back();
  return str;
}

