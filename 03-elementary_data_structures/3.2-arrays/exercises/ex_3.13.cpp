#include<iostream>
#include<array>
#include<vector>

int main()
{
    constexpr unsigned N = 100;
    std::array<unsigned, N> y_axis_primes;
    for(std::size_t i = 0; i != y_axis_primes.size(); i++)
        y_axis_primes[i] = i;

    //y_it represents vertical N values. I'm lazy and any orientation requires
    //a huge screen so N can be adjusted for smaller figures
    //We need to add 3 to start computing [0] [1] [2]
    auto y_it = y_axis_primes.begin() + 3;
    for(; y_it != y_axis_primes.end();y_it++){
        //We create a temporary prime vector for each y-axis value.
        //This of course hurts performance.
        std::vector<unsigned> x_axis_primes;
        x_axis_primes.resize(*y_it);
        auto x_it = x_axis_primes.begin()  + 2;
        std::fill(x_it, x_axis_primes.end(), 1);
        for(std::size_t i = 2; i != x_axis_primes.size(); i++){
            if(x_axis_primes[i])
                for(std::size_t j = i; i * j < *y_it; j++)
                    x_axis_primes[i * j] = 0;
        }
        //Visual hack for showing vertical axis correctly
        std::cout<< *(y_it - 1) << " : ";
        std::for_each(x_axis_primes.begin(), x_axis_primes.end(),
                        [](auto prime_values)
                        {
                            if(prime_values == 1)
                                std::cout<<" * ";
                        });
        std::cout<<std::endl;
    }

    return 0;
}
