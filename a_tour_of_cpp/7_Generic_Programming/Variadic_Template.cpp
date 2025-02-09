// cl /std:c++17 /I \. .\Variadic_Template.cpp

#include <iostream>
#include <string>
#include <vector>

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

#pragma region Fold Expression

template<typename... T>
int sum(T... v)
{
    return (v + ... + 0); // (v[0]+(v[1]+(v[2]+(v[3]+(v[4]+0)))))
    // return (0 + ... + v); // (((((0+v[0])+v[1])+v[2])+v[3])+v[4])
}

template<typename... T>
void printT(T&&... args)
{
    (std::cout << ... << args) << '\n';
}

template<typename Res, typename... Ts>
std::vector<Res> to_vector(Ts&&... ts)
{
    std::vector<Res> res;
    (res.push_back(ts), ...); // no init value needed
    return res;
}

template<typename... Ts>
void fct(Ts&&... ts)
{
    auto args = to_vector<std::string>(ts...);
    // further use args
}

void useToVec()
{
    // can use to simple copy args to vector for further use
    auto x = to_vector<double>(1, 2, 4.5, 'a');
    fct("foo", "bar");
}

#pragma endregion

int main()
{
    user();
    std::cout << sum(1, 2, 3) << std::endl;
    printT("Hello!"s, ' ', "World ", 2017);
    useToVec();
}