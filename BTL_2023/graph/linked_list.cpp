#include "node_iterator.cpp"
#ifndef _linked_list_CPP
#define _linked_list_CPP
using namespace std;
template <class T>
class Don_list
{
    node<T> *head, *tail;
    int num;

public:
    Don_list()
    {
        head = tail = nullptr;
        num = 0;
    }
    int size() { return num; }
    bool empty() { return num == 0; }
    T &front() { return head->getE(); }
    T &back() { return tail->getE(); }
    Don_list &operator = (const Don_list&x){
        head = new node<T>;
        head = x.head;
        num= x.num;
        tail = new node<T>;
        tail= x.tail;
        return *this;
    }
    void push_front(T x)
    {
        node<T> *temp = new node<T>;
        temp->setNext(head);
        temp->setE(x);
        head = temp;
        if (!num)
            tail = temp;
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
            if (tail == p)
                tail = temp;
            num++;
        }
    }
    void push_back(T x)
    {
        insert(cuoi().getnode(), x);
    }
    void erase_head()
    {
        if (!num)
            return;
        if (num == 1)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        node<T> *temp = new node<T>;
        temp = head->getNext();
        head = temp;
        delete temp;
        num--;
    }
    void erase(node<T> *p)
    {
        if (!num)
            return;
        if (p == nullptr)
            return;
        node<T> *temp = p->getNext();
        p->setNext(temp->getNext());
        delete temp;
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
            temp = head;
            while (temp->getNext() != tail)
            {
                temp = temp->getNext();
            }
            erase(temp);
            tail=temp;
        }
    }
    iter<T> dau() { return head; }
    iter<T> cuoi() { return tail; }
};
#endif