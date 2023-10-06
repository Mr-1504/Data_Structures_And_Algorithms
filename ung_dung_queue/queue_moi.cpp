#include <bits/stdc++.h>
#ifndef _queue_cpp
#define _queue_cpp
using namespace std;
template <class T>
class queue_moi
{
    int n, cap, f, l;
    T *a;

protected:
    void extend()
    {
        cap = cap ? cap * 2 : 1;
        T *temp = new T[cap];
        for (int i = f, j = 0; i < f + n; i++, j++)
            temp[j] = a[i % n];
        f = 0;
        l = n;
        delete[] a;
        a = temp;
    }

public:
    queue_moi()
    {
        n = cap = f = l = 0;
        a = nullptr;
    }
    ~queue_moi()
    {
        delete[] a;
    }
    bool empty() { return n == 0; }
    int size() { return n; }
    void pop()
    {
        if (n > 0)
        {
            n--;
            f = ++f % cap;
            if (!n)
                f = l = 0;
        }
    }

    void push(T x)
    {
        if (n == cap)
        {
            extend();
        }
        a[l % cap] = x;
        l = l >= cap ? l % cap : ++l;
        n++;
    }
    T &front() { return a[f]; }
    T &back()
    {
        if (l == 0)
            return a[cap - 1];
        return a[l - 1];
    }
};
#endif