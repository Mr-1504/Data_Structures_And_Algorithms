#include "danh_sach_can_bo.cpp"
using namespace std;
int main()
{
    list_cb a;
    a.create_list();
    
    string x;
    cin.ignore(1);
    cout<<"Nhap chuc vu can tim: ";
    getline(cin,x);
    a.display();
    a.search(x);
    cout<<"\n-5";
    return 0;
}