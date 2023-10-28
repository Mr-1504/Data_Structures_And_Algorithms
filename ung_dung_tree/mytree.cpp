#include <bits/stdc++.h>
#ifndef _tree_hi_hi
#define _tree_hi_hi
using namespace std;
template <class T>
class node
{
    T value;
    int n = 0, _l = 0, _r = 0;
    node<T> *left = nullptr;
    node<T> *right = nullptr;

public:
    node() {}
    node(T x)
    {
        value = x;
        n = 1;
    }
    void push(T x)
    {
        if (n == 0)
            value = x;
        else if (x < value)
        {
            _l++;
            if (left == nullptr)
                left = new node<T>(x);
            else
                left->push(x);
        }
        else if (x > value)
        {
            _r++;
            if (right == nullptr)
                right = new node<T>(x);
            else right->push(x);
        }
        n++;
    }
    int size() { return n; }
    void print()
    {
        if (left != nullptr)
            left->print();
        int temp = n - _l - _r;
        for (int i = 0; i < temp; i++)
            cout << value << " ";
        if (right != nullptr)
            right->print();
    }
};
#endif