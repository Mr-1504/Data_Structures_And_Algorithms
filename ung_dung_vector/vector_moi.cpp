#include <iostream>
#ifndef vector_moi_C
#define vector_moi_C
using namespace std;
template <class T>
class vector_moi
{
    int n, so_phan_tu_max;
    T *a;

public:
    bool rong()
    {
        return n == 0;
    }
    int ptu_max()
    {
        return so_phan_tu_max;
    }
    int sophantu()
    {
        return n;
    }
    vector_moi()
    {
        so_phan_tu_max = 1;
        n = 0;
        a = new T[1];
    }
    vector_moi(int k, T temp)
    {
        so_phan_tu_max = n = k;
        a = new T[k];
        for (int i = 0; i < n; i++)
            a[i] = temp;
    }
    vector_moi(T *arr, T *arr_cuoi)
    {
        so_phan_tu_max = n = arr_cuoi - arr;
        a = new T[n];
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }
    void bo_o_cuoi()
    {
        if (n > 0)
            n--;
    }
    void morong(int cap)
    {
        if (so_phan_tu_max < cap)
            so_phan_tu_max = cap;
        else
            return;
        T *temp = new T[so_phan_tu_max];
        for (int i = 0; i < n; i++)
            temp[i] = a[i];
        delete[] a;
        a = temp;
    }
    void chen(int vitri, T giatri)
    {
        if (so_phan_tu_max == n)
            morong(2 * n);
        for (int i = n - 1; i >= vitri; i--)
            a[i + 1] = a[i];
        a[vitri] = giatri;
        n++;
    }
    void xoa(int vitri)
    {
        for (int i = vitri; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }
    void xoa(int dau, int cuoi)
    {
        T *temp = new T[so_phan_tu_max];
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (i == dau)
                j = cuoi + 1;
            temp[i] = a[j];
            i++;
            j++;
        }
        delete[] a;
        a = temp;
        n = i;
    }
    T &operator[](int k)
    {
        return a[k];
    }
    void doi_kick_thuoc(int newsize)
    {
        T *temp = new T[newsize];
        if (newsize < n)
        {
            for (int i = 0; i < newsize; i++)
                temp[i] = a[i];
            n = newsize;
        }
        else
            for (int i = 0; i < n; i++)
                temp[i] = a[i];
    }
    void doi_kick_thuoc(int newsize, int giatri)
    {
        T *temp = new T[newsize];
        if (newsize < n)
            for (int i = 0; i < newsize; i++)
                temp[i] = a[i];
        else
        {
            for (int i = 0; i < n; i++)
                temp[i] = a[i];
            for (int i = n + 1; i < newsize; i++)
                temp[i] = giatri;
        }
        n = newsize;
    }
    void them_cuoi(T x)
    {
        if (so_phan_tu_max == n)
            morong(2 * n);
        a[n] = x;
        n++;
    }
    void hoan_doi(vector_moi<T> &b)
    {
        int sptm, cnt;
        if (b.so_phan_tu_max > so_phan_tu_max)
            n = sptm = b.so_phan_tu_max;
        else
            sptm = so_phan_tu_max = b.so_phan_tu_max;
        T *temp = new T[sptm];
        temp = a;
        cnt = n;
        a = b.a;
        n = b.sophantu();
        b.a = temp;
        b.n = cnt;
    }
    void giai_phong(){
        so_phan_tu_max = 1;
        n = 0;
        a = new T[1];
    }
    void themchen(int vitri, T  giatri){
       chen(vitri, giatri);
    }
    void themchen_cuoi(T giatri){
        them_cuoi(giatri);
    }
};
#endif