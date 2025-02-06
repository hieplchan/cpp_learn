#include <list>
#include <string>

#include "Vector.h"

#pragma region Example1
template<typename C>
using Value_type = typename C::value_type;

template<typename Container>
void algo(Container& c)
{
    Vector<Value_type<Container>> vec;
}
#pragma endregion

#pragma region Example2
template<typename Key, typename Value>
class Map {};

template<typename Value>
using String_map = Map<std::string, Value>;
#pragma endregion

int main()
{
    std::list<int> l1;
    algo(l1);   //vec = Vector<int>
    
    String_map<int> m1; // m = Map<string, int>
}