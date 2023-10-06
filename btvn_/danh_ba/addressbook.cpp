#include <bits/stdc++.h>
#include "contact.cpp"
#include "vector_moi.cpp"
#ifndef _danh_ba_cpp
#define _danh_ba_cpp
using namespace std;
int cmp(const void *a, const void *b)
{
    contact *x = (contact *)a;
    contact *y = (contact *)b;
    return x->name_contact() < y->name_contact();
}
class AddressBook
{
    vector_moi<contact> a;

public:
    void add_contact()
    {
        cout << "----------------------------------\n";
        cout << "Them lien he moi:\n";
        cout << "\t1. Nhap 1 lien he.\n";
        cout << "\t2. Nhap nhieu lien he.\n";
        cout << "\t3. Quay lai.\n";
        int cnt;
        cout << "\t";
        cin >> cnt;
        switch (cnt)
        {
        case 1:
        {
            contact x;
            cin >> x;
            a.them_cuoi(x);
            break;
        }
        case 2:
        {
            int n;
            cout << "Nhap so lien he them moi: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                contact x;
                cin >> x;
                a.them_cuoi(x);
            }
            break;
        }
        case 3:
            return;
        default:
            cout << "\nThao tac khong hop le!\n\n";
            break;
        }
        cout << "\nNhap thanh cong!\n\n";
        cout << "----------------------------------\n";
        cout << "\nNhap phim bat ky de quay lai: ";
        char y;
        cin >> y;
    }
    void erase()
    {
        cout << "----------------------------------\n";
        cout << "Xoa lien he theo:\n";
        cout << "\t1. Ho ten.\n";
        cout << "\t2. So dien thoai.\n";
        cout << "\t3. Email.\n";
        int cnt;
        cout << "\t";
        cin >> cnt;
        switch (cnt)
        {
        case 1:
        {
            cout << "Nhap ho ten lien he can xoa: ";
            string x;
            cin.ignore(1);
            getline(cin, x);
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (a[i].name_contact() == x)
                {
                    temp = true;
                    a.xoa(i);
                }
            }
            if (temp)
                cout << "Xoa thanh cong!\n\n";
            else
                cout << "Khong co lien he trung khop\n\n";
        }
        break;
        case 2:
        {
            cout << "Nhap so dien thoai lien he can xoa: ";
            string x;
            cin >> x;
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (a[i].number_phone() == x)
                {
                    temp = true;
                    a.xoa(i);
                }
            }
            if (temp)
                cout << "Xoa thanh cong!\n\n";
            else
                cout << "Khong co lien he trung khop\n\n";
            break;
        }
        case 3:
        {
            cout << "Nhap email lien he can xoa: ";
            string x;
            cin >> x;
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (a[i].email_contact() == x)
                {
                    temp = true;
                    a.xoa(i);
                }
            }
            if (temp)
                cout << "Xoa thanh cong!\n\n";
            else
                cout << "Khong co lien he trung khop\n\n";
            break;
        }
        default:
            cout << "Thao tac khong hop le!\n";
            break;
        }
        cout << "----------------------------------\n";
        cout << "\nNhap phim bat ky de quay lai: ";
        char y;
        cin >> y;
    }
    void search()
    {
        cout << "----------------------------------\n";
        cout << "Ban muon tim theo:\n";
        cout << "\t1. Ho ten.\n";
        cout << "\t2. So dien thoai.\n";
        cout << "\t3. Email.\n";
        int cnt;
        cin >> cnt;
        switch (cnt)
        {
        case 1:
        {
            cout << "Nhap ho ten can tim: ";
            string x;
            cin.ignore(1);
            getline(cin, x);
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (x == a[i].name_contact())
                {
                    if (!temp)
                    {
                        cout << "\nDanh sach cac lien he tim thay: \n";
                        temp = true;
                    }
                    cout << a[i] << endl;
                }
            }
            if (!temp)
                cout << "Khong tim thay lien he!\n";
            break;
        }
        case 2:
        {
            cout << "Nhap so dien thoai can tim: ";
            string x;
            cin >> x;
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (x == a[i].number_phone())
                {
                    if (!temp)
                    {
                        cout << "\nDanh sach cac lien he tim thay: \n";
                        temp = true;
                    }
                    cout << a[i] << endl;
                }
            }
            if (!temp)
                cout << "Khong tim thay lien he!\n";
            break;
            cout << "\nNhap phim bat ky de quay lai: ";
            char y;
            cin >> y;
        }
        case 3:
        {
            cout << "Nhap email can tim: ";
            string x;
            cin >> x;
            bool temp = false;
            for (int i = 0; i < a.sophantu(); i++)
            {
                if (x == a[i].email_contact())
                {
                    if (!temp)
                    {
                        cout << "\nDanh sach cac lien he tim thay: \n";
                        temp = true;
                    }
                    cout << a[i] << endl;
                }
            }
            if (!temp)
                cout << "Khong tim thay lien he!\n";
            break;
        }
        default:
            cout << "Thao tac khong hop le!\n";
            break;
            cout << "----------------------------------\n";
        }
        cout << "\nNhap phim bat ky de quay lai: ";
        char y;
        cin >> y;
    }
    void sort()
    {
        for (int i = 0; i < a.sophantu(); i++)
        {
            for (int j = i; j < a.sophantu(); j++)
            {
                if (a[i].name_contact() > a[j].name_contact())
                {
                    contact x = a[i];
                    a[i] = a[j];
                    a[j] = x;
                }
            }
        }
    }
    void list_contact()
    {
        sort();
        cout << "Danh sach cac lien he:\n";
        for (int i = 0; i < a.sophantu(); i++)
        {
            cout << a[i] << endl;
        }
    }
    int size() { return a.sophantu(); }
};
#endif