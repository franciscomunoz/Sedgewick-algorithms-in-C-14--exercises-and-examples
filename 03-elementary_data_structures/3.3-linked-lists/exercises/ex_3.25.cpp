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
void mergeLists(list, list);
void printList(list);
void deleteList(list);

int main()
{
    constexpr unsigned N = 5;
    list listx = nullptr;
    list listt= nullptr;

    createCircularList(listx,N);
    createCircularList(listt,N);
    mergeLists(listx,listt);
    printList(listx);
    printList(listt);
    deleteList(listx);
    deleteList(listt);
    return 0;
}

void createCircularList(list &a_node, unsigned n)
{
    //Creates a basic increasing list`
    a_node = new node(1, nullptr); a_node->next = a_node;
    list x = a_node;
    //Advance x creating nodes and a_node closes the loop to  form a circular list
    for (unsigned i = 2; i <= n; i++)
        x = (x->next = new node(i, a_node));
}

void mergeLists(list node_a, list node_b)
{
    if(node_a == nullptr || node_b == nullptr)
        return;
    list x = node_a;
    list t = node_b;
    list last_xnode = nullptr;

    //if single node list
    if(x->next == x){
        last_xnode = x;
    }
    else{
        for(;x->next != node_a; x = x->next){}
            last_xnode = x;
    }
    //If single node this will not run
    for(; t->next != node_b ; t = t->next){
        list new_node = new node(t->item,nullptr);
        last_xnode->next = new_node;
        last_xnode = new_node;
    }
    //two escenarios are considered here.
    //1._run and need to wrap
    //2._loop above never runs and its single node
    if(t->next == node_b){
        list new_node = new node(t->item,nullptr);
        last_xnode->next = new_node;
        new_node->next = node_a;
    }
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
