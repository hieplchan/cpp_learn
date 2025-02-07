// cl /std:c++17 /I \. .\Variadic_Template.cpp

#include <iostream>
#include <string>

using namespace std::literals::string_literals;

// void print()
// {
//     // no args = nothing to do
// }

template<typename T, typename... Tail>
void print(T head, Tail... tail)
{
    std::cout << head << ' ';
    if constexpr(sizeof...(tail) > 0) // compile-time if -> no need for empty args printf
        print(tail...);
}

void user()
{
    print("first: ", 1, 2.2, "hello\n"s); // first: 1 2.2 hello
    print("\nsecond: ", 0.2, 'c', "yuck!"s, 0, 1, 2, '\n');
}

int main()
{
    user();
}