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
int josephusFunction(list, unsigned);

int main()
{
    list listx = nullptr;
    constexpr unsigned a_size = 4;

    for(unsigned i = 2; i < 1000; i++){
        createCircularList(listx,i);
        auto jf = josephusFunction(listx, 10);
        std::cout<<i<<"  : ";
        for(int j = 0; j < jf; j+=50)
            std::cout << "*";
        std::cout<<std::endl;
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

int josephusFunction(list node, unsigned M)
{
    list x = node;
    while(x != x->next){
        for(unsigned i = 1; i < M; i++){
            x = x->next;
        }
        x->next = x->next->next;
    }
    return x->item;
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

