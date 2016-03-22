#include "list.h"
//Make pass any function that returns 0 or nonzero values
template<typename T>
int whatever(std::shared_ptr<ListNode<T>> node)
{
    return node->getData()%2;
}

int main()
{

    std::function<int(std::shared_ptr<ListNode<int>>)> f = (int(*)(std::shared_ptr<ListNode<int>>))&whatever;
/*
    List<int> list1{1,2,3,4,5,6,7,8,9,10,11,12};
    list1.print();
    list1.removeUsingFunction(f);
    list1.print();
*/
    List<int> list2{2,4,6,8,9,11};
    list2.removeUsingFunction(f);
    list2.print();
    return 0;
}
