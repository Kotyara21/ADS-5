// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  std::string post; 
    TStack<char, 100> stack1; 

    std::map<char, int> priorities = {
        {'(', 0},
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2}
    };
    for (char c : inf) {
        if (c == ' ') 
            continue;
        if (std::isdigit(c)) { 
            post += c;
            post += ' ';
        } else if (c == '(') { 
            stack1.push(c);
        } else if (c == ')') { 
            while (!stack1.isEmpty() && stack1.get() != '(') {
                post += stack1.pop();
                post += ' ';
            }
            stack1.pop(); 
        } else { 
            while (!stack1.isEmpty() && priorities[stack1.get()] >= priorities[c]) {
                post += stack1.pop();
                post += ' ';
            }
            stack1.push(c);
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
  return std::string("");
}
int eval(std::string pref) {
  TStack<int, 100> stack2; 

    for (char c : post) {
        if (c == ' ')
            continue;  
        if (std::isdigit(c)) {
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
  return 0;
}
