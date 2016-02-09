#include<iostream>
#include<array>

int main()
{
    constexpr int array_size = 99;
    std::array<int, array_size> a;

    for(std::size_t i = 0; i != a.size(); i++)
        a[i] = 98 - i;
    for(std::size_t i = 0; i != a.size(); i++)
        a[i] = a[a[i]];

    return 0;
}


