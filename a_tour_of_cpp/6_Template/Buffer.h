template<typename T, int N>
struct Buffer
{
    using value_type = T;
    constexpr int size() { return N; }
    T buffer[N];

    T& operator[](int i) { return buffer[i]; }
};