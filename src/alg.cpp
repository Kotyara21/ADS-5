// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
bool isOper(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int isPrior(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
std::string infx2pstfx(std::string inf) {
  stack<char, 100> stack;
  std::string postfix;
  int length = infix.length();
  for (int i = 0; i < length; ++i) {
    char c = infix[i];
    if (isspace(c)) {
      continue;
    } else if (isdigit(c)) {
      postfix += c;
      postfix += ' ';
    } else if (isOper(c)) {
      int pri = isPrior(c);
      while (!stack.empty() && stack.get() != '(' && isPrior(stack.get()) >= pri) {
        postfix += stack.pop();
        postfix += ' ';
      }
      stack.push(c);
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.empty() && stack.top() != '(') {
        postfix += stack.pop();
        postfix += ' ';
      }
        stack.pop();
    }
  }
  while (!stack.empty()) {
    postfix += stack.pop();
    postfix += ' ';
  }
  if (!postfix.empty()) {
    postfix.pop_back();
  }
  return postfix;
}
int eval(std::string pref) {
  TStack<int, 100> stack;
  int lenght = pref.length();
  for (int i = 0; i < lenght; i += 2) {
    char c = pref[i];
    if (isdigit(c)) {
      int num = c - '0';
      stack.push(num);
    } else if (Oper(c)) {
      int op2 = stack.pop();
      int op1 = stack.pop();
      int result;
      switch (c) {
        case '+': result = op1 + op2;
          break;
        case '-': result = op1 - op2;
          break;
        case '*': result = op1 * op2;
          break;
        case '/': result = op1 / op2;
          break;
      }
      stack.push(result);
    }
  }
  return stack.pop();
}
