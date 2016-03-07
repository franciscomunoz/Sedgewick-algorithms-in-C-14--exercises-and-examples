#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <memory>
#include <initializer_list>
#include "listnode.h"

template<typename T>
class List
{
public:
    List();
    List(std::initializer_list<T>);
    List(List<T>&& lst);
    ~List();
    void moveLargestItemToEnd();
    void moveSmallestItemToFront();
    void reorderOddEvenNodes();
    List<T> copyList();
    void insertAtBack(const T&);
    void print() const;
    bool isEmpty() const;
private:
    std::shared_ptr<ListNode<T>> firstPtr;
    std::shared_ptr<ListNode<T>> lastPtr;
};

//Default ctor
template<typename T>
List<T>::List()
    :firstPtr{nullptr},lastPtr{nullptr}
{
}

template<typename T>
List<T>::List(List<T>&& lst)
{
    firstPtr = lst.firstPtr;
    lastPtr = lst.lastPtr;
    lst.firstPtr = nullptr;
    lst.lastPtr = nullptr;
}
//New ctor type using initializer lists
template<typename T>
List<T>::List(std::initializer_list<T> lst)
    :firstPtr{nullptr},lastPtr{nullptr}
{
    std::for_each(lst.begin(),lst.end(),
                    [=](T item)
                    {
                        insertAtBack(item);
                    });
}

template<typename T>
List<T>::~List()
{
    if(!isEmpty()){
        while(firstPtr != nullptr){
            firstPtr=firstPtr->next;
        }
    }
}

template<typename T>
void List<T>::moveLargestItemToEnd()
{
    auto currentPtr = firstPtr->next;
    auto behindPtr  = firstPtr;
    auto maxPtr     = firstPtr;
    std::shared_ptr<ListNode<T>> behindMaxPtr = nullptr;
    if( !isEmpty()){
        if(currentPtr != nullptr){
            while(currentPtr != nullptr){
                if(currentPtr->getData() > maxPtr->getData()){
                    maxPtr = currentPtr;
                    behindMaxPtr = behindPtr;
                }
                currentPtr=currentPtr->next;
                behindPtr=behindPtr->next;
            }
        }
        //If max is the first node and list is made of more than 1 node
        if(behindMaxPtr == nullptr && maxPtr->next != nullptr){
            firstPtr = firstPtr->next;
            lastPtr->next = maxPtr;
            lastPtr = maxPtr;
            maxPtr->next = nullptr;
        }//In between list
        else if(behindPtr != nullptr && maxPtr->next != nullptr)
        {
            behindMaxPtr->next= maxPtr->next;
            lastPtr->next = maxPtr;
            maxPtr->next = nullptr;
        }
        //If max is at then end, then we ignore it
    }
}

template<typename T>
void List<T>::moveSmallestItemToFront()
{
    std::shared_ptr<ListNode<T>>  currentPtr = nullptr;
    auto behindPtr  = firstPtr;
    auto minPtr     = firstPtr;
    std::shared_ptr<ListNode<T>> behindMinPtr = nullptr;
    if( !isEmpty()){
    currentPtr = firstPtr->next;
        if(currentPtr != nullptr){
            while(currentPtr != nullptr){
                if(currentPtr->getData() < minPtr->getData()){
                    minPtr = currentPtr;
                    behindMinPtr = behindPtr;
                }
                currentPtr=currentPtr->next;
                behindPtr=behindPtr->next;
            }
        }
    }
    //If min is at the end of the list
    if(minPtr->next == nullptr && behindMinPtr != nullptr){
        lastPtr = behindMinPtr;
        lastPtr->next = nullptr;
        minPtr->next = firstPtr;
        firstPtr = minPtr;
    }//In list
    else if(behindMinPtr != nullptr && minPtr->next != nullptr){
        behindMinPtr->next = minPtr->next;
        minPtr->next = firstPtr;
        firstPtr = minPtr;
    }

}

template<typename T>
void List<T>::reorderOddEvenNodes()
{
    std::shared_ptr<ListNode<T>> oddElements;
    std::shared_ptr<ListNode<T>> evenElements;
    std::shared_ptr<ListNode<T>> oddFirstPtr;
    std::shared_ptr<ListNode<T>> evenFirstPtr;
    bool odd = true;
    if(!isEmpty()){
        oddFirstPtr = oddElements = firstPtr;
        firstPtr = firstPtr->next;

        if(firstPtr){
            evenFirstPtr = evenElements = firstPtr;
            firstPtr = firstPtr->next;
        }
        else{
            return; //List has a single element so why try to sort it?
        }
    }
    else{
            return; //List is empty !!
    }
   //Alternate even and odd nodes
    while(firstPtr != nullptr){
        if(odd){
            oddElements->next = firstPtr;
            oddElements = oddElements->next;
            firstPtr = firstPtr->next;
            odd = false;
        }
        else{
            evenElements->next = firstPtr;
            evenElements = evenElements->next;
            firstPtr = firstPtr->next;
            odd = true;
        }
    }
    //reconnect list
    oddElements->next = evenFirstPtr;
    firstPtr = oddFirstPtr;
}

//This is the function which matters for this exercise
template<typename T>
List<T> List<T>::copyList()
{
    List<T> newList;
    for(auto currentNode = firstPtr; currentNode != nullptr; currentNode = currentNode->next){
        newList.insertAtBack(currentNode->getData());
    }
   return newList;
}

template<typename T>
void List<T>::insertAtBack(const T& item)
{
    auto newNode =  std::make_shared<ListNode<T>>(item);
    if(isEmpty()){
        firstPtr = lastPtr = newNode;
    }
    else{
        lastPtr->next = newNode;
        lastPtr = newNode;
    }
}

template<typename T>
void List<T>::print() const
{
    for(auto currentNode = firstPtr; currentNode != nullptr;currentNode=currentNode->next)
    {
        std::cout << currentNode->getData() << " ";
    }
    std::cout << std::endl;

}

template<typename T>
bool List<T>::isEmpty() const
{
    return  firstPtr == nullptr;
}

#endif
