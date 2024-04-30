// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int Priority(char c) {
    if (c == '(')
        return 0;
    else if (c == ')' || c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return -1;
}

std::string infx2pstfx(std::string inf) {
 std::string post;
    TStack<char, 100> stack1;

    for (char c : inf) {
        if (c == ' ')
            continue;

        if (Priority(c) == -1) {
            post += c;
            post += ' ';
        } else {
            if (c == ')') {
                while (stack1.get() != '(') {
                    post += stack1.pop();
                    post += ' ';
                }
                stack1.pop();
            } else if (c == '(' || stack1.isEmpty() || Priority(stack1.get()) < Priority(c)) {
                stack1.push(c);
            } else {
                while (!stack1.isEmpty() && Priority(stack1.get()) >= Priority(c)) {
                    post += stack1.pop();
                    post += ' ';
                }
                stack1.push(c);
            }
        }
    }
    while (!stack1.isEmpty()) {
        post += stack1.pop();
        post += ' ';
    }
    if (!post.empty())
        post.pop_back();

    return post;
}

int eval(std::string pref) {
 TStack<int, 100> stack2;

    for (char c : post) {
        if (c == ' ')
            continue;
        if (Priority(c) == -1) {
            int num = 0;
            while (std::isdigit(c)) {
                num = num * 10 + (c - '0');
                ++i;
                c = post[i];
            }
            stack2.push(num);
        } else {
            int b = stack2.pop();
            int a = stack2.pop();
            switch (c) {
                case '+':
                    stack2.push(a + b);
                    break;
                case '-':
                    stack2.push(a - b);
                    break;
                case '*':
                    stack2.push(a * b);
                    break;
                case '/':
                    stack2.push(a / b);
                    break;
            }
        }
    }
    return stack2.get();
}
