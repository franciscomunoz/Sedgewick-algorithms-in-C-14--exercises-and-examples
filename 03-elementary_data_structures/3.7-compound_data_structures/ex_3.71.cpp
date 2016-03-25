#include <iostream>
#include <algorithm>
#include <vector>

int ** malloc2d(int N, int M)
{
	int ** r = new int*[N];
	for(int i = 0; i < N; i++){
		r[i] = new int[M];
	}
	return r;
}


int main(int c, char *v[])
{
	bool are_coordinates_even = (c-1)%2 == 0 ? true : false;
	if(!are_coordinates_even){
		std::cout << "Error : please check the amount of coordinates " <<std::endl;
		return -1;
	}
	//Find the highest coordinate value provided using point_vector
	std::vector<unsigned> point_vector;
	std::vector<unsigned> unsorted_coordinates;
	for(auto it = v+1; it!= v + c; it++){
		point_vector.push_back(atoi(*it));
	}
	unsorted_coordinates = point_vector;
	//Sort to find max value in order to determine matrix dimensions
	std::sort(point_vector.begin(),point_vector.end());
	//Add 1 to matrix size alloc. This is becasue of the size is determined by
	//the highest coordinate value.
	unsigned V = (*(point_vector.end() - 1))+1;

	int **adj = malloc2d(V,V);

	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++)
			adj[i][j] = 0;
	}
	//By definition a vertex is connected to itself
	for (int i = 0; i < V; i++)
		adj[i][i] = 1;

	auto it = unsorted_coordinates.begin();
	int x,y;
	while(true){
		if(it != unsorted_coordinates.end())
			x = *it;
		else
			break;
		std::advance(it,1);
		if(it != unsorted_coordinates.end())
			y = *it;
		else
			break;
		
		adj[x][y] = 1;
		adj[y][x] = 1;
		std::advance(it,1);
    }
	return 0;
}
