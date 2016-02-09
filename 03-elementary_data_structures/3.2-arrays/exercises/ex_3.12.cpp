#include<iostream>
#include<array>
#include<vector>

int main()
{
    constexpr unsigned n_1 = 1000;
    constexpr unsigned n_2 = 10000;
    constexpr unsigned n_3 = 100000;
    constexpr unsigned n_4 = 1000000;

    std::array<unsigned,4> n_vals ={n_1, n_2, n_3, n_4};

    std::vector<long> vector1;
    vector1.resize(n_1);
    std::vector<long> vector2;
    vector2.resize(n_2);
    std::vector<long> vector3;
    vector3.resize(n_3);
    std::vector<long> vector4;
    vector4.resize(n_4);

    std::vector<std::vector<long>> primes{vector1, vector2, vector3, vector4};
    //iterare over vector
    std::for_each(primes.begin(),primes.end(),
                       [](auto & prime_buf)
                    {
                            //Offset iterator in order to start doing primes at x[2]
                            auto it_offset = prime_buf.begin() + 2;
                            std::fill(it_offset,prime_buf.end(),1);
                            for(std::size_t i = 2; i != prime_buf.size(); i++){
                                if(prime_buf[i])
                                    for(std::size_t j = i; (j * i) < prime_buf.size(); i++){
                                        prime_buf[i *j] = 0;
                                    }
                            }
                    });

    //Print any of the vectors for showing primes
    return 0;
}
