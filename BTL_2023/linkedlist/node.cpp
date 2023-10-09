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