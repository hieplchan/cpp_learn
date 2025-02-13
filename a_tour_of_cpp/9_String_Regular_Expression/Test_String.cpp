#include <string>
#include <iostream>

using namespace std::literals::string_literals;
using std::string;

#define LOG(x) std::cout << x << std::endl

string g_sIncantation;
void testCompare(const string& ans)
{
    if (ans >= g_sIncantation)
    {
        //...
    }

    if (ans == "abc")
    {
        //...
    }
}

void print(const string& s)
{
    printf("For people who like CString: %s\n", s.c_str());
    std::cout << "For people who like streams: " << s << '\n';
}

string compose(const string& name, const string& domain)
{
    return name + '@' + domain;
}

int main()
{
    auto addr = compose("dmr", "bell-labs.com");
    LOG(addr);

    addr = addr + '\n';
    addr += '\n'; // prefer this way more

    string s = addr.substr(2, 4);
    LOG(s);

    addr.replace(2, 6, "abcdefgh");
    LOG(addr);

    addr[0] = toupper(addr[0]);
    LOG(addr);

    print(addr);

    // String literals
    auto s = "acbd"s; // std::string literal
    auto s = "abcd"; // C-style string (const char*) literal
}