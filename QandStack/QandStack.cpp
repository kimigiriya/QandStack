#include "QandStack.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <locale.h>


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 >> null");

    std::string palindrome;
    std::cout << "Введите строку для проверки на палиндром: ";
    std::getline(std::cin, palindrome);

    if (isPalindrome2(palindrome)) {
        std::cout << "\"" << palindrome << "\" - это палиндром." << "\n";
    }
    else {
        std::cout << "\"" << palindrome << "\" - это не палиндром." << "\n";
    }

    std::string parenthesis;
    std::cout << "Введите строку со скобками: ";
    std::getline(std::cin, parenthesis);

    if (FullMetallParenthesis(parenthesis)) {
        std::cout << "Скобки в строке \"" << parenthesis << "\" сбалансированы." << "\n";
    }
    else {
        std::cout << "Скобки в строке \"" << parenthesis << "\" не сбалансированы." << "\n";
    }

    return 0;
}