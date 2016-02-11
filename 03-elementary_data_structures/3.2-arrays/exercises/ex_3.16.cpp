#include<iostream>
#include<fstream>

int main()
{
    std::ifstream file{"ex_3.16_input.txt",std::ios_base::in};
    unsigned input_int;
    unsigned count = 0;
    while(file >> input_int){
        if(input_int < 1000){
            count++;
        }
    }
    std::cout<<"There are " << count << " integers less than 1000" << std::endl;

    return 0;
}
