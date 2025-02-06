template<typename T>
void simple_and_fast(T& data) {}

template<typename T>
void slow_and_safe(T& data) {}

template<typename T>
void algo(T& data)
{
    if constexpr(std::is_pod<T>::value) // is_pod = plain old data = trivial to copy
        simple_and_fast(data);
    else
        slow_and_safe(data);
}

int main()
{
    int a;
    algo(a);
}