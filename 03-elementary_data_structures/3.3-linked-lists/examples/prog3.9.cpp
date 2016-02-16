#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int item; node* next;
    node(int x, node* t)
      { item = x; next = t; }
};

typedef node *list;

int main(int argc, char *argv[])
{
    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    list t = new node(1, 0); t->next = t;
    list x = t;
    //Advance x creating nodes but t stays so that list remain closet
    for (i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    while (x != x->next)
    {
        //Disconect nodes but does not delete :D
        for (i = 1; i < M; i++) x = x->next;
            x->next = x->next->next;
    }
    cout << x->item << endl;
    return 0;
}

