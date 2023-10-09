#include <bits/stdc++.h>
#ifndef _node_CPP
#define _node_CPP
using namespace std;
template <class T>
class node
{
    T data;
    node *next;

public:
    node() {}
    node(T data)
    {
        next = new node;
        next = nullptr;
        this->data = data;
    }
    node &operator = (const node&x){
        data=x.data;
        next = x.next;
        return *this;
    }
    void setE(T x) { data = x; }
    void setNext(node<T> *x) { next = x; }
    T &getE() { return data; }
    node<T> *&getNext() { return next; }
    ~node()
    {
        delete next;
    }
};
#endif