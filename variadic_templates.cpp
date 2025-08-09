#include <iostream>
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


template<template<typename> class Predicat, typename ...Types>
struct count_if;

template<template<typename> class Predicat>
struct count_if<Predicat> {
    enum { val = 0; }
};

template <template<typename> class Predicat, typename T, typename ...Types>
struct count_if<Predicat, T, Types ...> {
    enum {val = Pred<T>::value + count_if<Predicat, Types...>}::val;
};