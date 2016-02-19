#include <iostream>
#include <array>


int main()
{
    //we just demonstraed the principle of josephus using the array(next) rewriting
    //its contents. Then we obtain the item value using the x
    constexpr unsigned N = 9;
    constexpr unsigned M = 4;
    std::array<unsigned,N> item{1,2,3,4,5,6,7,8,9};
    std::array<unsigned,N> next{1,2,3,4,5,6,7,8,0};
    unsigned x = 0;
    while(x != next[x]){
        for(unsigned i = 1; i < M; i++){
            x = next[x];
        }
        next[x] = next[next[x]];
    }
    std::cout << "Josephus function with arrays of N = " << N << " is : " << item[x] << std::endl;

    return 0;
}
