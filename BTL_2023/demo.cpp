#include "danh_sach_can_bo.cpp"
using namespace std;
int main()
{
    list_cb a;
    a.create_list();
    a.add();
    a.display();
    cout<<"Nhap chuc vu can tim: ";
    string x;
    cin.ignore(1);
    getline(cin,x);
    a.search(x);
    return 0;
}