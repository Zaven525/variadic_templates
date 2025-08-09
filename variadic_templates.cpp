#include <iostream>
#include <string>
#include <algorithm>
// template<typename ...Args>
// void print(Args ...args) {
//     ((std::cout << args), ...);
// }

// int main() {
//     print(32, 32.4, "Hello", 'A');

//     return 0;
// }


// template<typename T>
// void print(T a) {
//     return;
// }

// template<typename T, typename ...Args>
// void print(T arg, Args ...args) {
//     std::cout << arg;
//     print(args...);
// }

// int main() {
//     print(32, 32.4, "Hello", 'A');

//     return 0;
// }


// template<template<typename> class Predicat, typename ...Types>
// struct count_if;

// template<template<typename> class Predicat>
// struct count_if<Predicat> {
//     enum { val = 0; }
// };

// template <template<typename> class Predicat, typename T, typename ...Types>
// struct count_if<Predicat, T, Types ...> {
//     enum {val = Pred<T>::value + count_if<Predicat, Types...>}::val;
// };


template<typename First>
void print_with_sep(std::string sep, First first) {
    std::cout << first << std::endl;
}

template<typename First, typename ...Args>
void print_with_sep(std::string sep, First first, Args...args) {
    std::cout << first << sep;
    print_with_sep(sep, args...);
}

std::string to_upper(const std::string& s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(), ::toupper);
    return res;
}

template<typename First>
void print_upper(std::string sep, First first) {
    std::cout << to_upper(first) << std::endl;
}

template<typename First, typename ...Args>
void print_upper(std::string sep, First first, Args ...args) {
    std::cout << to_upper(first) << sep;
    print_upper(sep, args...);
}

std::string compress(std::string str) {
    std::string res;
    for (char i : str) {
        if (i != ' ') {
            res += i;
        }
    }
    return res;
}


template<typename First>
void print_compressed(First first) {
    std::cout << compress(first) << std::endl;
}

template<typename First, typename ...Args>
void print_compressed(First first, Args ...args) {
    std::cout << compress(first);
    print_compressed(args...);
}


int main() {
    print_with_sep(", ", "apple", "banan");
    print_upper(", ", "apple", "banan");
    print_compressed("Hello World", "hihi haha");

    return 0;
}