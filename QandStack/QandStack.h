#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cctype>

bool isPalindrome(const std::string& str) {
    std::stack<char> s;
    std::queue<char> q;

    for (char c : str) {
        s.push(c);
        q.push(c);
    }

    while (!s.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }

    return true;
}

bool isPalindrome2(const std::string& str) {
    std::stack<char> s;
    std::queue<char> q;
    std::string processedStr = "";

    for (char c : str) {
        char lower = std::tolower(c);
        if (lower != ' ' and lower != ',' and lower != '-' and lower != '.' and lower != '!' and lower != '?') {
            processedStr += lower;
        }
    }

    for (char c : processedStr) {
        s.push(c);
        q.push(c);
    }

    while (!s.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }
    return true;
}

bool FullMetallParenthesis(const std::string& str) {
    std::stack<char> s;
    std::string open = "({[<";
    std::string close = ")}]>";

    for (char c : str) {
        if (open.find(c) != std::string::npos) {
            s.push(c);
        }
        else if (close.find(c) != std::string::npos) {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' and top != '(') or (c == '}' and top != '{') or (c == ']' and top != '[') or (c == '>' and top != '<')) {
                return false;
            }
        }
    }

    return s.empty();
}

bool FullMetallParenthesis2Brotherhood(const std::string& str) {
    std::stack<char> s;
    std::string openClose = "(){}[]<>";

    int openCount = 0;
    int closeCount = 0;

    for (char c : str) {
        if (openClose.find(c) != std::string::npos) {
            if (std::string("({[<").find(c) != std::string::npos) {
                openCount++;
                s.push(c);
            }
            else if (std::string(")}]>").find(c) != std::string::npos) {
                closeCount++;
            }
        }
    }
    return openCount == closeCount;
}