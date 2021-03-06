#include<iostream>
#include<vector>
#include<cmath>
int main()
{
    const std::vector<unsigned>  r = {10, 100, 1000};
    const std::vector<unsigned long>  N = {1000, 10000, 100000, 1000000};
    for(auto it: r){
        std::for_each(N.begin(),N.end(),
                       [it](auto n)
                        {
                            double m1 = 0, m2 = 0;
                            for(unsigned i = 0; i < n; i++){
                                    double r_number = (std::rand()%it);
                                    //Compute average and variance
                                    m1 += static_cast<double>(r_number)/n;
                                    m2 += static_cast<double>(r_number * r_number)/n;
                            }
                            std::cout<<"Avg.        :"<< m1 <<std::endl;
                            std::cout<<"Std dev.    :"<< sqrt(m2-m1*m1) << std::endl;
                        });
    }
    return 0;
}

