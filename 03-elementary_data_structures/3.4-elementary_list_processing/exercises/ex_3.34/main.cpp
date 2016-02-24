#include "list.h"


int main()
{

    List<int> list1{0,40,10,5,6,3,-1,8,50,10,15,20};
    list1.print();
    list1.moveSmallestItemToFront();
    list1.print();

    List<int> list2{40};
    list2.print();
    list2.moveSmallestItemToFront();
    list2.print();

    List<int> list3{40,10};
    list3.print();
    list3.moveSmallestItemToFront();
    list3.print();



    return 0;
}
