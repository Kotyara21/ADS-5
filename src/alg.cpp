// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
bool isOper(char c) {
  return (c == '+' || c == '-' || c == '*' c == '/');
}
int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
std::string infx2pstfx(std::string inf) {
  std::string postfix;
