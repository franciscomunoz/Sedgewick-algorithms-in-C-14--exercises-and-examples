#include <iostream>
#include <cstdlib>

struct node
{
    int item; node* next;
    node(int x, node* t)
      { item = x; next = t; }
};

typedef node *list;

void createCircularList(list &, unsigned);
void printList(list);
void deleteList(list);

int main()
{
    constexpr unsigned N = 5;
    list listx = nullptr;

    createCircularList(listx,N);
    printList(listx);
    deleteList(listx);
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

void printList(list node)
{
    if(node == nullptr)
        return;
    list x = node;
    if(x == node->next){
        std::cout << node->item << std::endl;
        return; //Avoid the other print below if single node
    }
    while(node != x->next){
        std::cout << x->item;
        x = x->next;
    }
    //The list wraps so this is why an extra print
    std::cout << x->item << std::endl;
}

void deleteList(list node)
{
    list temp; //used for deleting
    list x = node->next; //start at next
    list referenceNode = node;
    while (x != referenceNode){
        temp = x;
        x = x->next;
        delete temp;
    }
    delete referenceNode;
}
