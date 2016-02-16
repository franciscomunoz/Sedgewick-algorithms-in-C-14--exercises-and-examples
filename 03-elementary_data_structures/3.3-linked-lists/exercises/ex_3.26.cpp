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
void moveNodes(list nodex, list nodet);
void printList(list);
void deleteList(list);

int main()
{
    constexpr unsigned N = 5;
    list listx = nullptr;

    //Pointers used for moving nodes
    list nodex = nullptr;
    list nodet = nullptr;
    createCircularList(listx,N);
    printList(listx);
    //Points used for sorting nodes
    nodex = nodet = listx;
    nodex = nodex->next->next;
    nodet = nodet->next->next->next->next;
    //if list elemets are 1 2 3 4 5, then
    //after calling the function list becomes 1 4 2 3 5, this  of course
    //is considering current positions for both nodex and nodet
    moveNodes(nodex, nodet);
    printList(listx);
    deleteList(listx);
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
//Disconect and reconect nodes considering the limitation of single linked lists
void moveNodes(list nodex, list nodet)
{
    //We need to find the nodes position following the node
    //following x
    list x_follower = nodex;
    while(x_follower->next->next != nodex)
        x_follower = x_follower->next;
    //We need to find the nodes position following the node t
    list t_follower = nodet;
    while(t_follower->next->next != nodet)
        t_follower = t_follower->next;

    //Obtain pointer to t
    list tempt = t_follower->next;
    //Conect nodes skipping tempt
    t_follower->next = t_follower->next->next;
    //reconect node  following node following x
    tempt->next = x_follower->next;
    x_follower->next = tempt;
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
