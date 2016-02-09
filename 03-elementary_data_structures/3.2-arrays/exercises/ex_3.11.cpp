#include<iostream>
#include<chrono>
#include<array>

constexpr int N = 1000;
constexpr int N_bits = 32; //32 * 32 possible entries
//n/32 bit number mapped into array index by dividing
//k%32 is location of bit to be set whitin index
void setBit(std::array<int, N_bits>& A,  int n )
{
	A[n/32] |= 1 << (n%32);
}

void clearBit(std::array<int,N_bits>& A,  int n )
{
	A[n/32] &= ~(1 << (n%32));
}

bool getBitValue(std::array<int, N_bits>& A, int n)
{
	return ((A[n/32] & (1 << (n%32))) != 0);
}

int main()
{

    //This algorithm zeroes the products i*j which means not prime
    //In conclusion bits took more time , but less space when compared to the char
    //representation
    //Array of bits
	std::array<int,N_bits> a_bits;

	for(std::size_t i = 2; i != N; i++)
		setBit(a_bits, i);
    auto start = std::chrono::steady_clock::now();
	//array indexes are accessed using helper functions above.
	for(std::size_t i = 2; i != N; i++){
		if(getBitValue(a_bits,i)){
			for(std::size_t j = i; j * i < N; i++){
				clearBit(a_bits, i * j);
            }
		}
	}

    auto end = std::chrono::steady_clock::now();
    auto  diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    //Array of chars
    std::array<char,N> a_char;

    for(std::size_t i = 2; i != N; i++)
        a_char[i] = '1';

    start = std::chrono::steady_clock::now();
    for(std::size_t i = 2; i != N; i++){
        if(a_char[i] == '1'){
            for(std::size_t j = i; j * i < N; i++){
               a_char[i * j] = '0';
            }
        }
    }

    end = std::chrono::steady_clock::now();
    auto  diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    for(std::size_t i = 2; i < N; i++){
		if(getBitValue(a_bits,i))
			std::cout << "bits :" << i << "       ";

		if(a_char[i] == '1')
			std::cout << "chars : " << i << std::endl;
	}

	std::cout<< "Execution time for array of bits  : " << diff1 << " microseconds" << std::endl;
	std::cout<< "Execution time for array of chars : " << diff2 << " microseconds" << std::endl;

    return 0;
}



