#include <iostream>
#include <algorithm>
#include <vector>

/*
 * The main purpose of this exercise is : given a pair of vertices a,b.
 * Find vertex C values  with the property that there is an edge from a to
 * c and from c to b. The function vertexes implements this.
 */
//Foolish method. Must consider RAII
int ** malloc2d(int N, int M)
{
	int ** r = new int*[N];
	for(int i = 0; i < N; i++){
		r[i] = new int[M];
	}
	return r;
}

struct vertex{
    int a;
    int b;
};

//Just prints a square matix holding Vertexes V
void print_matrix(int **adj_matrix, unsigned V)
{
    std::cout<<" ";
    for (int i = 0; i < V;i++)
        std::cout<<" "<<i;
    std::cout<<std::endl;
    for (int i = 0; i < V; i++){
        std::cout<<i<<" ";
        for (int j = 0; j < V; j++)
            std::cout<<adj_matrix[i][j]<<" ";
        std::cout<<std::endl;
    }
}

const std::vector<int> vertexes(int **adj_matrix, vertex ab, unsigned V){

    std::vector<int> vertex_c;
    for (int i = 0; i < V; i++){
        if ( adj_matrix[i][ab.a] && adj_matrix[i][ab.b])
            vertex_c.push_back(i);
    }
    return vertex_c;
}

int main(int c, char *v[])
{
    //The user types a sequence of edges as input, then adjacency Matrix is
    //assembled. By convention the main diagonal is 1 since each vertex is
    //connected to itself, but this is not implemented here.
    vertex v_ab = {0,0};
	bool are_coordinates_even = (c-1)%2 == 0 && c > 1? true : false;
	if(!are_coordinates_even){
		std::cout << "Error : please check the amount of coordinates " <<std::endl;
		return -1;
	}
    std::cout << "\nType vertices for finding vertex values  C : "<<std::endl;
    std::cin >> v_ab.a >> v_ab.b;

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

    print_matrix(adj,V);
    std::cout << "\nVertex C values are : " << std::endl;
    for ( auto i: vertexes(adj,v_ab,V))
        std::cout << i << " ";
	return 0;
}


