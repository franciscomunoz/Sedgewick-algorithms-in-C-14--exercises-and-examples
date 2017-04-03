#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
/*
 * The main purpose of this exercise is : given a pair of vertices a,b.
 * Find vertex C values  with the property that there is an edge from a to
 * c and from c to b. The function vertexes implements this.
 */
/*Quick and dirty list implementation*/
template<typename T>
struct node{
    T data;
    std::shared_ptr<node> next;
    node(T d, const std::shared_ptr<node<T>> &n):data(d),next(n){}
};

template<typename T>
using link = std::shared_ptr<node<T>>;

template<typename T>
struct vertex{
    T a;
    T b;
};

//This function assumes non-repeated nodes are passed
template<typename T>
const std::vector<T> vertexes(const std::vector<link<T>> &v, const vertex<T> &ab)
{
    link<T> trv;
    std::vector<int> vertex_c;
    //count is independet of template type.
    int count = 0;
    for (auto it = v.begin(); it != v.end(); it++){
        for (trv = *it; trv != nullptr; trv = trv->next){
            if (trv->data == ab.a || trv->data == ab.b)
                count++;
        }
        if (count == 2)
            vertex_c.push_back(std::distance(v.begin(),it));
        count = 0;
    }
    return vertex_c;
}

int main(int argc, char *argv[])
{
    if (argc != 2){
        std::cerr<<"Vertex  and nodes are required !\n";
        return 1;
    }
    //j represent the jth linked list of nodes conected to
    //the i vextex
    int i,j;
    int c = 0;
    std::vector<link<int>> adj;
    vertex<int> v_ab = {0,0};
    auto v = atoi(argv[1]);
    //From 0 to V inclusive
    adj.resize(v + 1);

    for (int i = 0; i < v; i++)
        adj[i] = nullptr;
    //This implementation does not eliminate repeated edges. We could use
    //the linked list implementation for previous sections. Data is inserted
    //as pairs indicating "from" "to" edges.
    while (std::cin >> i >> j){
        if (i == -1 || j == -1) break;
        adj[j] = std::make_shared<node<int>>(i,adj[j]);
        adj[i] = std::make_shared<node<int>>(j,adj[i]);
    }
    std::cout << "\nType vertices for finding vertex values  C : "<<std::endl;
    std::cin >> v_ab.a >> v_ab.b;
    std::cout << "\nVertex C values are : " << std::endl;
    for (auto i: vertexes(adj,v_ab))
        std::cout << i << " \n";

    return 0;
}
