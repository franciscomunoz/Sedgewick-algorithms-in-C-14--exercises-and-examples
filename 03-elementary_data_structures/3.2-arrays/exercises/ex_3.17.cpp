#include<iostream>
#include<array>
#include<cmath>
#include<ctime>
int main()
{
    constexpr unsigned length = 1000000;
    constexpr unsigned max  = 1000;
    std::array<unsigned, length> values;
    //A single realization of a random vector
    std::srand(std::time(0));
    std::for_each(values.begin(), values.end(),
                    [](auto &currentValue)
                    {
                        currentValue = std::rand()%max;
                    });
    //Just use a value for searching it inside the buffer
    unsigned count = 0;
    unsigned repeated = 0;
    //When repeated is 1, the count starts until repeated is two
    auto random_value = values[0];
    for(std::size_t i = 1; i < values.size(); i++){
        if(values[i] == random_value){
            repeated++;
        }
        if(repeated == 1){
            count++;
        }
        else if(repeated == 2){
            break;
        }
    }
    if(repeated == 2){
        std::cout<<"The amount of random values before obtaining a repeated is : " <<\
            count << std::endl;
    }
    else{
            std::cout << "It was not possible to determine a repetition count. Try again! " <<\
                    std::endl;
    }
    return 0;
}

