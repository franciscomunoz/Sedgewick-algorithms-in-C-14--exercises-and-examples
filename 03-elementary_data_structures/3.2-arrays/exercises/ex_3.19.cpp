#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

auto heads()
{
    return std::rand() <  RAND_MAX/6;
}

int main(int argc, char *argv[])
{
    unsigned exp_trials = 1000;
    unsigned N = 32;
    unsigned head_count = 0;

    std::vector<unsigned> frequency;
    frequency.resize(N);
    std::fill(frequency.begin(),frequency.end(), 0);
    //Trials
    for(unsigned i = 0; i < exp_trials; i++){
        //Perform coin 0...N-1 flips
        head_count = 0;
        for(unsigned j = 0;  j < N; j++){
            if(heads())
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
