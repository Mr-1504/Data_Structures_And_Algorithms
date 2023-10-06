#include <iostream>
#include "vector_moi.cpp"
using namespace std;
int main()
{
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector_moi<int> a(c, c + 10);
    a.bo_o_cuoi();
    for (int i = 0; i < a.sophantu(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    a.chen(2, 10);
    for (int i = 0; i < a.sophantu(); i++)
    {
        cout << a[i] << " ";
    }
    a.xoa(2,5);
    cout << endl;
    for (int i = 0; i < a.sophantu(); i++)
    {
        cout << a[i] << " ";
    }
    a.them_cuoi(100);
    cout << endl;
    for (int i = 0; i < a.sophantu(); i++)
    {
        cout << a[i] << " ";
    }
    vector_moi<int> b(c, c+10);
    a.hoan_doi(b);
    cout << endl;
    for (int i = 0; i < a.sophantu(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.sophantu(); i++)
    {
        cout << b[i] << " ";
    }
    a.giai_phong();
    cout<<endl<<a.sophantu()<<" "<<a.ptu_max()<<endl;
    a.themchen_cuoi(3);
}