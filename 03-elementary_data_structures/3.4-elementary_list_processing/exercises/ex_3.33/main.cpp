#include "list.h"


int main()
{
    List<int> list1{1,40,5,6,3,7,8,50,10,15,20};
    list1.print();
    list1.moveLargestItemToEnd();
    list1.print();

    List<int> list2{40};
    list2.print();
    list2.moveLargestItemToEnd();
    list2.print();

    List<int> list3{40,10};
    list3.print();
    list3.moveLargestItemToEnd();
    list3.print();




    return 0;
}
