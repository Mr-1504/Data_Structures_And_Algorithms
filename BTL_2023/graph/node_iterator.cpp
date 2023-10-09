#include "node.cpp"
#ifndef _iterator_CPP
#define _iterator_CPP
using namespace std;
template <class T>
class iter
{
    node<T> *a;

public:
    iter() { a = nullptr; }
    iter(node<T> *x) { a = x; }
    node<T> *getnode() { return a; }
    void setnode(node<T> *x) { 
        a=new node<T>;
        a=x; }
    iter<T> &operator=(iter<T> x)
    {
        this->a = x.getnode();
        return *this;
    }
    bool operator!=(iter<T> x) { return a != x.getnode(); }
    iter<T> operator++()
    {
        a->getNext();
        return a;
    }
    iter<T> operator++(int)
    {
        node<T> *temp=*this;
        a = a->getNext();
        return temp;
    }
    T &operator*()
    {
        return a->getE();
    }
};
#endif