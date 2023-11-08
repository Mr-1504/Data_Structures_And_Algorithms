#include "node_iterator.cpp"
#ifndef _linked_list_CPP
#define _linked_list_CPP
using namespace std;
template <class T>
class Don_list
{
    node<T> *head, *end;
    int num;

public:
    Don_list()
    {
        head = end = nullptr;
        num = 0;
    }
    ~Don_list(){
        delete head;
        delete end;
    }
    int size() { return num; }
    bool empty() { return num == 0; }
    T &front() { return head->getE(); }
    T &back() { return end->getE(); }
    iter<T> dau() { return head; }
    iter<T> cuoi() { return end; }
    void push_front(T x)
    {
        node<T> *temp = new node<T>;
        temp->setNext(head);
        temp->setE(x);
        head = temp;
        if (!num)
            end = temp;
        num++;
    }
    void insert(node<T> *p, T x)
    {
        if (!num)
            push_front(x);
        else
        {
            node<T> *temp = new node<T>;
            temp->setNext(p->getNext());
            p->setNext(temp);
            temp->setE(x);
            if (end == p)
                end = temp;
            num++;
        }
    }
    void push_back(T x)
    {
        insert(cuoi().getnode(),x);
    }
    void erase_head()
    {
        if (!num)
            return;
        if (num == 1)
        {
            head = end = nullptr;
            return;
        }
        node<T> *temp = new node<T>;
        temp = head->getNext();
        head = temp;
        num--;
    }
    void erase(node<T> *p)
    {
        node<T> *temp = p->getNext();
        p = temp->getNext();
        num--;
    }
    void pop_front()
    {
        erase_head();
    }
    void pop_back()
    {
        if (num < 2)
            erase_head();
        else
        {
            node<T> *temp = new node<T>;
            while (temp->getNext() != end)
            {
                temp++;
            }
            erase(temp);
        }
    }
};
#endif