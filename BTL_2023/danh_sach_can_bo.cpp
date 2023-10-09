#include "can_bo.cpp"
#include "linked_list.cpp"
#ifndef _danh_sach_cpp
#define _danh_sach_cpp
using namespace std;
class list_cb
{
    Don_list<can_bo> a;

public:
    list_cb() {}
    list_cb(Don_list<can_bo> a)
    {
        this->a = a;
    }
    void create_list()
    {
        cout << "Tao danh sach can bo\n";
        int i = 0;
        while (1)
        {
            cout << "Nhap thong tin can bo thu " << ++i << endl;
            can_bo temp;
            if (!temp.input())
                break;
            a.push_back(temp);
        }
        // sort();
    }
    void add()
    {
        cout << "Ban muon chon vi tri se them?\n";
        cout << "\t1. Chon vi tri.\n";
        cout << "\t2. Khong chon\n";
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
        {
            cout << "\tChon vi tri muon them: ";
            int n;
            cin >> n;
            can_bo temp;
            cin >> temp;
            if (n == 1)
                a.push_front(temp);
            else if (n == a.size() + 1)
                a.push_back(temp);
            else
            {
                int i = 0;
                node<can_bo> *x = new node<can_bo>;
                iter<can_bo> y;
                y = a.dau();
                x = y.getnode();
                while (i < n - 1 && x != nullptr)
                {
                    y++;
                    x = y.getnode();
                }
                a.insert(x, temp);
            }
            break;
        }
        case 2:
        {
            can_bo temp;
            cin >> temp;
            a.push_back(temp);
            break;
        }
        default:
            cout << "\tThao tac khong hop le!\n";
            break;
        }
    }
    void sort()
    {
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            for (iter<can_bo> j = i; j != nullptr; j++)
            {
                can_bo X = i.getnode()->getE();
                can_bo Y = j.getnode()->getE();
                if (X.Ten() > Y.Ten())
                {
                    j.getnode()->setE(X);
                    i.getnode()->setE(Y);
                }
                else if (X.Ho() > Y.Ho())
                {
                    j.getnode()->setE(X);
                    i.getnode()->setE(Y);
                }
            }
        }
    }
    void display()
    {
        sort();
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            can_bo temp = i.getnode()->getE();
            if (temp.he_so_luong() >= 4.4)
            {
                if (!j)
                    cout << "Danh sach cac can bo co he so luong tren 4.4 la:\n";
                cout << ++j << ". " << temp << endl;
            }
        }
        if (!j)
            cout << "Khong co can bo co he so luong tren 4.4\n";
        return;
    }
    void search(string cvu)
    {
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            can_bo temp = i.getnode()->getE();
            if (temp.chuc_vu() == cvu)
            {
                if (!j)
                    cout << "Danh sach cac can bo co chuc vu " << cvu << " la" << endl;
                cout << ++j << ". " << temp << endl;
            }
        }
        if (!j)
            cout << "Khong co can bo giu chuc vu " << cvu << endl;
        return;
    }
    void search(float hsl, string phong)
    {
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            can_bo temp = i.getnode()->getE();
            if (temp.he_so_luong() == hsl && temp.phong_ban() == phong)
            {
                if (!j)
                    cout << "Danh sach cac can bo co he so luong tren 4.4 o phong ban " << phong << "la:\n";
                cout << ++j << ". " << temp << endl;
            }
        }
        if (!j)
            cout << "Khong co can bo co he so luong " << hsl << " o phong " << phong << endl;
        return;
    }
};
#endif