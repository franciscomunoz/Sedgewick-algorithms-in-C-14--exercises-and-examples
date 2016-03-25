#include <iostream>


int *** malloc3d(int r, int c, int k)
{
    int *** a = new int **[k]; 

    for(int i = 0; i < r; i++){
        a[i] = new int*[i];
        for(int j = 0; j < c; j++){
        	a[i][j] = new int[j];
        }
    }
    return a;
}

int main()
{
    int M = 2;
    int N = 2;
    int O = 2;
    int  ***a = malloc3d(M,N,O);

    return 0;
}

