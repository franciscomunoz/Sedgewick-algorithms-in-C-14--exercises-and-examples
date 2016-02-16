#include <iostream>
#include <cstdlib>

struct node
{
    int item; node* next;
    node(int x, node* t)
      { item = x; next = t; }
};

typedef node *list;

unsigned countListNodes(list);
void deleteList(list);

int main(int argc, char *argv[])
{
    constexpr unsigned N = 1;
    list t = new node(1, 0); t->next = t;
    list x = t;
    //Advance x creating nodes but t stays so that list remain closet
    for (unsigned i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    auto count = countListNodes(t);
    std::cout << "The number of nodes in a circular list is :" << count << std::endl;
    deleteList(t);
    return 0;
}

unsigned countListNodes(list node)
{
    if(node == nullptr)
        return 0;

    list referencePoint = node;
    list x = node->next;
    //single node list
    if(referencePoint == x)
        return 1;
    //otherwise count
    unsigned count = 1;
    for(;x != referencePoint; x = x->next)
            count++;
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
