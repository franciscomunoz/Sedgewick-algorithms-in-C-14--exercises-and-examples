#include <iostream>
#include <cstdlib>
#include <array>
struct node
{
    int item; node* next;
    node(int x, node* t)
      { item = x; next = t; }
};

typedef node *list;

void createCircularList(list &, unsigned);
void josephusFunction(list, unsigned);

int main()
{
    list listx = nullptr;
    constexpr unsigned a_size = 4;

    std::array<unsigned,a_size> M{2,3,5,10};
    std::array<unsigned,a_size> N{1000,10000,100000,1000000};

    for(unsigned i = 1; i < N.size(); i++){
        createCircularList(listx,N[i]);
        josephusFunction(listx, M[i]);
    }
    return 0;
}

void createCircularList(list &a_node, unsigned n)
{
    //Creates a basic increasing list`
    a_node = new node(1, nullptr); a_node->next = a_node;
    list x = a_node;
    //Advance x creating nodes and set the next new node to NULL
    for (unsigned i = 2; i <= n; i++)
        x = (x->next = new node(i, nullptr));
    //This is where the list loop is established
    x->next = a_node;
}

void josephusFunction(list node, unsigned M)
{
    list x = node;
    while(x != x->next){
        for(unsigned i = 1; i < M; i++){
            x = x->next;
        }
        x->next = x->next->next;
    }
    std::cout << "The josephus function for M = " << M << " is : " << x->item << std::endl;
}

void printList(list node)
{
    if(node == nullptr)
        return;
    list x = node;
    if(x == node->next){
        std::cout << node->item << std::endl;
        return; //Avoid the other print below if single node list
    }
    while(node != x->next){
        std::cout << x->item;
        x = x->next;
    }
    //The list wraps so this is why an extra print
    std::cout << x->item << std::endl;
}

