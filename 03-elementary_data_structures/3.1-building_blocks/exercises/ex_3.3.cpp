#include<iostream>
#include<vector>
#include<cmath>
int main()
{
    const std::vector<unsigned>  r = {10, 100, 1000};
    const std::vector<unsigned long>  N = {1000, 10000, 100000, 1000000};
    //Hack for double rand resolution
    const  unsigned  local_rand_max = 100000;
    for(auto it: r){
        std::for_each(N.begin(),N.end(),
                       [it](auto n)
                        {
                            double m1 = 0, m2 = 0;
                            for(unsigned i = 0; i < n; i++){
                                    double r_number = static_cast<double>(std::rand()%local_rand_max)/local_rand_max;
                                    unsigned r_product = std::ceil(r_number * it);
                                    //Compute average and variance
                                    m1 += static_cast<double>(r_product)/n;
                                    m2 += static_cast<double>(r_product * r_product)/n;
                            }
                            std::cout<<"Avg.        :"<< m1 <<std::endl;
                            std::cout<<"Std dev.    :"<< sqrt(m2-m1*m1) << std::endl;
                        });
    }
    return 0;
}

