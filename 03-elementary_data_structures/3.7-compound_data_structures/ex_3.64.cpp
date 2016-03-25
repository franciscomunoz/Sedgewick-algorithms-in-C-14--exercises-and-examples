#include<iostream>
#include <array>
#define N 10
#define M 10
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
	c = a; 
	a = b%a;  b = c;
  }
  return b;
}
int main()
{
	//Sets matrix point to 1 in terms of gcd
	std::array<std::array<int,M>,N> matrix = {0};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(gcd(i,j) == 1)
				matrix[i][j] = 1;	
		}
	} 
    return 0;
}
