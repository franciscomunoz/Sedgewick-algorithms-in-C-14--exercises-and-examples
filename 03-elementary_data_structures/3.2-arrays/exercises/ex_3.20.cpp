#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

const unsigned exp_trials = 1000;
const unsigned N = 32;

auto heads(unsigned l)
{
    return std::rand() <  RAND_MAX * (l/static_cast<float>(N));
}

int main()
{
    unsigned head_count = 0;
    unsigned l = 0;
    std::cout <<"Enter the lambda for poisson :"<<std::endl;
    std::cin >> l;
    std::vector<unsigned> frequency;
    frequency.resize(N);
    srand(time(NULL));
    std::fill(frequency.begin(),frequency.end(), 0);
    //Trials
    for(unsigned i = 0; i < exp_trials; i++){
        //Perform coin 0...N-1 flips
        head_count = 0;
        for(unsigned j = 0;  j < N; j++){
            if(heads(l))
                head_count++;
        }
    frequency[head_count]+=1;
    }
    //Print frequencies
    for(unsigned i = 0; i < N; i++){
        if(frequency[i] == 0)
            std::cout<<".";
        for(unsigned j = 0; j < frequency[i]; j+=10){
            std::cout << "*";
        }
        std::cout<<std::endl;
    }

    return 0;
}
