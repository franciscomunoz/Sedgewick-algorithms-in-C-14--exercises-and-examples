#include<iostream>
#include<array>
#include<cmath>
#include<ctime>
int main()
{
    constexpr unsigned max  = 1000;
    std::array<unsigned, max> values;
    //A single realization of a random vector
    std::srand(std::time(0));
    //Holds the amount of random numbers generated less than 1000 before getting
    //every value repeated at least once
    unsigned count = 0;
    while(true){
        auto currentValue = std::rand()%max;
        values[currentValue]++;
        unsigned elements_above_one = 0;
        for(std::size_t i = 0; i < values.size();i++)
            if(values[i] >= 1)
                    elements_above_one++;
        if(elements_above_one == max)
            break;
        else
            count++;
    }
    for(std::size_t i = 0; i < values.size();i++){
            if(values[i] == 1)
                std::cout << "=======>Random values that were at least 1 once"<<"  "<< i << std::endl;
    }
    std::cout << "The number of generated random numbers less than 1000 before getting each\
        at least once is :" << count << std::endl;
    return 0;
}
