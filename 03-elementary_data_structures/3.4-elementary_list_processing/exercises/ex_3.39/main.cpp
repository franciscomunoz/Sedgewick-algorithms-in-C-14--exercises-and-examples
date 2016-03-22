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

    List<int> list1{1,2,3,4,5,6,7,8,9,10,11,12};
    list1.print();
    auto newList = list1.createListUsingFunction(f);
    newList.print();
    return 0;
}
