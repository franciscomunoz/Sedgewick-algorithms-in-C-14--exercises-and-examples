#ifndef LISTNODE_H
#define LISTNODE_H

#ifdef DEBUG
#define LOG(x) do {std::cerr << x << std::endl;  } while (0)
#else
#define LOG(x)
#endif

template<typename T> class List;

template<typename T>
class ListNode
{
    friend class List<T>;
public:
    explicit ListNode(const T&);
    ~ListNode();
    T getData() const;
private:
    T data;
    std::shared_ptr<ListNode<T>> next;
};

template<typename T>
ListNode<T>::ListNode::ListNode(const T &info)
    :data{info},next{nullptr}
{
}
template<typename T>
ListNode<T>::~ListNode()
{
	LOG(data);
}
template<typename T>
T ListNode<T>::getData() const
{
    return data;
}
#endif
