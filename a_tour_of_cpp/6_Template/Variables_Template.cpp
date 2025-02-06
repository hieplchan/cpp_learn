// https://www.youtube.com/watch?v=2kY-go52rNw&t=505s

// cl /std:c++17 /I \. .\Variables_Template.cpp

#include <iostream>
#include <string>
#include <type_traits>

using std::string;

#define LOG(x) std::cout << x << std::endl

template<typename T>
struct space_vector
{
    T x, y, z;
};

template<class T>
constexpr T viscosity = 0.4;

template<class T>
constexpr space_vector<T> external_acceleration = { T{}, T{-9.8}, T{} };

template<typename T, typename T2>
constexpr bool Assignable = std::is_assignable<T&, T2>::value;

#pragma region Variable Template Fib

template<int Value>
constexpr auto fib = fib<Value-1> + fib<Value-2>;

template<>
constexpr auto fib<0> = 0;

template<>
constexpr auto fib<1> = 1;

void testFibCompileTime()
{
    std::cout << fib<10> << std::endl;
}

#pragma endregion

template<typename T>
void testing()
{
    // compile time assert, if condition false, compile will be stopped
    static_assert(Assignable<T&, double>, "can't assign a double");
    static_assert(Assignable<T&, string>, "can't assign a string");
}

int main()
{
    auto vis2 = 2*viscosity<double>;
    auto acc = external_acceleration<float>;

    LOG(vis2);
    LOG(acc.x);
    LOG(acc.y);
    LOG(acc.z);

    testing<double>(); // stop compile when error
}