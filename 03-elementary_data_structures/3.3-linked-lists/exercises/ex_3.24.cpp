#include <iostream>
#include <cstdlib>

struct node
{
    int item; node* next;
    node(int x, node* t)
      { item = x; next = t; }
};

typedef node *list;

unsigned countListNodesBetweenNodes(list, list);
void deleteList(list);

int main(int argc, char *argv[])
{
    constexpr unsigned N = 10;
    list t = new node(1, 0); t->next = t;
    list x = t;
    //Advance x creating nodes but t stays so that list remain closet
    for (unsigned i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    //Reset x and use it for counting
    auto count = countListNodesBetweenNodes(t,x);
    std::cout << "The number of nodes in a circular list is :" << count << std::endl;
    deleteList(t);
    return 0;
}

unsigned countListNodesBetweenNodes(list node_a, list node_b)
{
    if(node_a == nullptr || node_b == nullptr)
        return 0;
    if(node_a == node_b)
        return 0;
    unsigned count = -1; //We want nodes between nodes without considering boundaries
    while(node_a != node_b){
        count++;
        node_a = node_a->next;
    }
    return count;
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
