#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
/*We take program 3.19 and reimplement it using C++14.
 * The idea of this problem was to dynamically
 * allocate an array of lists, but we stick to a vector and use RAII
 */


/*Quick and dirty list implementation*/
template<typename T>
struct node{
    T data;
    std::shared_ptr<node> next;
    node(T d, std::shared_ptr<node<T>> &n):data(d),next(n){}
};

template<typename T>
using link = std::shared_ptr<node<T>>;

int main(int argc, char *argv[])
{
    if (argc != 2){
        std::cerr<<"Vertex  and nodes are required !";
        return 1;
    }
    //j represent the jth linked list of nodes conected to
    //the i vextex
    int i,j;
    std::vector<link<int>> adj;
    auto v = atoi(argv[1]);
    adj.resize(v);

    for (int i = 0; i < v; i++)
        adj[i] = nullptr;
    while (std::cin >> i >> j){
        adj[j] = std::make_shared<node<int>>(i,adj[j]);
        adj[i] = std::make_shared<node<int>>(j,adj[i]);
    }
    return 0;
}
