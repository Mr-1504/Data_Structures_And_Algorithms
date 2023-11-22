#include <bits/stdc++.h>
#ifndef _q_sort_cpp_
#define _q_sort_cpp_
using namespace std;

template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = a;
}

template <class T>
void partition(T *a, int i, int j, int &right)
{
    T p = a[i];
    int left = i;
    right = j;
    while (left <= right)
    {
        while (a[left] <= p && left <= right)
            left++;
        while (a[right] > p )
            right--;
        if (left < right)
            swapp(a[left], a[right]);
    }
    a[i] = a[right];
    a[right] = p;
}

template<class T>
void q_sort(T *a, int i, int j){
    if(i < j){
        int right = j;
        partition(a, i, j, right);
        q_sort(a, i, right);
        q_sort(a, right + 1, j);
    }
}

#endif