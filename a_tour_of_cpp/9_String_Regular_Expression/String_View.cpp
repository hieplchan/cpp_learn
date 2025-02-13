// cl /std:c++17 /I \. .\String_View.cpp

#include <string>
#include <iostream>
#include <string_view>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;
using std::string, std::string_view;

#define LOG(x) std::cout << x << std::endl

// string_view {begin(), size()} -> point to same text data on memory
string cat(string_view sv1, string_view sv2)
{
    string res(sv1.length() + sv2.length(), ' ');
    char *p = &res[0];
    for (char c : sv1) // one way of copy
        *p++ = c;
    std::copy(sv2.begin(), sv2.end(), p); // another way of copy
    return res;
}

int main()
{
    string king = "Harold";
    auto s1 = cat(king, "William"); // string and C-style string (const char*)
    auto s2 = cat(king, king);
    auto s3 = cat(king, "asdada"sv); // string and string_view
    auto s4 = cat({&king[0], 2}, "Henry"); // "HaHenry"
    auto s5 = cat({&king[0], 2}, {&king[2], 4}); // "Harold"

    LOG(s1);
    LOG(s4);
    LOG(s5);
}