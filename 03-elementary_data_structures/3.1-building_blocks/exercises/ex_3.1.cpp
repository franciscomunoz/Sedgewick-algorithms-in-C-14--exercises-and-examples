#include<iostream>
#include<limits>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Minimum value for int : " << std::numeric_limits<int>::min() << '\n';
    std::cout << "Maximun value for int : " << std::numeric_limits<int>::max() << '\n';
    std::cout << "Minimum value for long : " << std::numeric_limits<long>::min() << '\n';
    std::cout << "Maximun value for long : " << std::numeric_limits<long>::max() << '\n';
    std::cout << "Minimum value for short : " << std::numeric_limits<short>::min() << '\n';
    std::cout << "Maximun value for short : " << std::numeric_limits<short>::max() << '\n';
    std::cout << "Minimum value for float : " << std::numeric_limits<float>::min() << '\n';
    std::cout << "Maximun value for float : " << std::numeric_limits<float>::max() << '\n';
    std::cout << "Minimum value for double : " << std::numeric_limits<double>::min() << '\n';
    std::cout << "Maximun value for double: " << std::numeric_limits<double>::max() << '\n';
}
