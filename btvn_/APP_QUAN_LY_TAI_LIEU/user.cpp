#include <bits/stdc++.h>
#include "folder.cpp"
#ifndef _user_cpp
#define _user_cpp
using namespace std;
class user
{
    string name;
    vector_moi<folder> a;

public:
    friend istream &operator>>(istream &cin, user &b)
    {
        cout << "Ten nguoi dung moi: ";
        cin.ignore(1);
        getline(cin, b.name);
        cout << "\t\nThem nguoi dung thanh cong!\n";
        return cin;
    }
    void erase_folder()
    {
        cout << "Ten thu muc muon xoa: ";
        string x;
        bool cnt = false;
        cin.ignore(1);
        getline(cin, x);
        for (int i = 0; i < a.sophantu(); i++)
        {
            if (x == a[i].name_folder())
            {
                a.xoa(i);
                cnt = true;
            }
        }
        if (cnt)
            cout << "Xoa thanh cong!\n";
        else
            cout << "Khong tim thay thu muc can xoa\n";
    }
    bool out()
    {
        folder a;
        if (a.out())
            return true;
        return false;
    }
    string name_user() { return name; }
    int spt() { return a.sophantu(); }
    void access_folder()
    {
        cout << "\n___________________________________________\n";
        cout << "|           DANH SACH THU MUC             |\n";
        if (a.sophantu() == 0)
        {
            cout << "|\t____________________________      |\n";
            cout << "|\t| Khong co thu muc nao!    |      |\n";
            cout << "|\t----------------------------      |\n";
        }
        else
        {
            cout << "|\t____________________________      |\n";
            for (int i = 0; i < a.sophantu(); i++)
            {
                cout << "|\t|" << i + 1 << ". " << left << setw(22) << a[i].name_folder() << " |      |" << endl;
            }
            cout << "|\t----------------------------      |\n";
        }
        int cnt = 0;
        cout << "|\t                                  |\n";
        cout << "|\t____________________________      |\n";
        if (a.sophantu())
        {
            cnt++;
            cout << "|\t|" << cnt << ". Truy cap thu muc.      |      |\n";
        }
        cout << "|\t|" << cnt + 1 << ". Tao thu muc moi.       |      |\n";
        cout << "|\t|" << cnt + 2 << ". Xoa thu muc.           |      |\n";
        cout << "|\t|" << cnt + 3 << ". Quay lai.              |      |\n";
        cout << "-------------------------------------------\n";
        cout << " \tChon tac vu:";
        int n;
        cin >> n;
        cout << "-------------------------------------------\n";
        if (n == cnt + 3)
            return;
        if (cnt)
        {
            switch (n)
            {
            case 1:
            {
                cout << "Truy cap thu muc thu: ";
                int k;
                cin >> k;
                if (k < 1 || k > a.sophantu())
                    cout << "So thu muc khong hop le!\n";
                else
                    a[k - 1].home_folder();
                break;
            }
            case 2:
            {
                folder x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\tTao thu muc thanh cong!\n";
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            case 3:
            {
                erase_folder();
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            default:
            {
                cout << "So tac vu khong hop le!\n";
                break;
            }
            }
        }
        else
        {
            switch (n)
            {
            case 1:
            {
                folder x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\tTao thu muc thanh cong!\n";
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            default:
                cout << "So tac vu khong hop le!\n";
                break;
            }
        }
        access_folder();
    }
    void home_user()
    {
        do
        {
            access_folder();
        } while (!out());
        return;
    }
};
#endif