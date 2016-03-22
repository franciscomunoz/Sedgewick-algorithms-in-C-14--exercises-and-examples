#include "list.h"


int main()
{

    List<int> list1{1,2,3,4,5,6,7,8,9,10,11,12};
    list1.print();
    list1.exchangeNodes(4,7);
    list1.print();
    return 0;
}
