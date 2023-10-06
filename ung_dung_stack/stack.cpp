#include <bits/stdc++.h>
#ifndef _stack_cpp
#define _stack_cpp
using namespace std;
template <class T>
class stack_moi
{
    int n, cap;
    T *a;

public:
    stack_moi()
    {
        n = cap = 0;
        a = nullptr;
    }
    ~stack_moi()
    {
        delete[] a;
    }
    bool emtyl() { return n == 0; }
    int size() { return n; }
    void pop()
    {
        if (n)
            n--;
    }
    void extend(int t)
    {
        if (cap == t)
            cap = t * 2;
        else
            return;
        T *temp = new T[cap];
        for (int i; i < n; i++)
            temp[i] = a[i];
        delete[] a;
        a = temp;
    }
    void push(int t)
    {
        extend(n);
        a[n++] = t;
    }
    T &top() { return n != 0 ? a[n - 1]; }
};
#endif