#include <bits/stdc++.h>
#include "user.cpp"
#ifndef _app_cpp
#define _app_cpp
using namespace std;
class app
{
    vector_moi<user> a;

public:
    friend istream &operator>>(istream &cin, app &b)
    {
        user x;
        cin >> x;
        b.a.them_cuoi(x);
        return cin;
    }
    void access_user()
    {
        cout << "\n___________________________________________\n";
        cout << "|           DANH SACH NGUOI DUNG          |\n";
        if (a.sophantu() == 0)
        {
            cout << "|\t____________________________      |\n";
            cout << "|\t| Khong co nguoi dung nao! |      |\n";
            cout << "|\t----------------------------      |\n";
        }
        else
        {
            cout << "|\t____________________________      |\n";
            for (int i = 0; i < a.sophantu(); i++)
            {
                cout << "|\t|" << i + 1 << ". " << left << setw(22) << a[i].name_user() << " |      |" << endl;
            }
            cout << "|\t----------------------------      |\n";
        }
        int cnt = 0;
        cout << "|\t                                  |\n";
        cout << "|\t____________________________      |\n";
        if (a.sophantu())
        {
            cnt++;
            cout << "|\t|" << cnt << ". Truy cap nguoi dung.   |      |\n";
        }
        cout << "|\t|" << cnt + 1 << ". Them nguoi dung moi.   |      |\n";
        cout << "|\t|" << cnt + 2 << ". Thoat.                 |      |\n";
        cout << "-------------------------------------------\n";
        cout << " \tChon tac vu:";
        int n;
        cin >> n;
        cout << "-------------------------------------------\n";
        if (n == cnt + 2)
            return;
        if (cnt)
        {
            switch (n)
            {
            case 1:
            {
                cout << "Truy cap nguoi dung thu: ";
                int k;
                cin >> k;
                if (k < 1 || k > a.sophantu())
                    cout << "So nguoi dung khong hop le!\n";
                else
                    a[k - 1].home_user();
                break;
            }
            case 2:
            {
                user x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            }
            if (n != 1 && n != 2)
                cout << "So tac vu khong hop le!\n";
        }
        else
        {
            switch (n)
            {
            case 1:
                user x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            if (n != 1)
                cout << "So tac vu khong hop le!\n";
        }
        access_user();
    }
    bool out(){
        user a;
        if(a.out()) return true;
        return false;
    }
    void home()
    {
        do
        {
            access_user();
        } while (!out());
    }
    void end_task()
    {
        cout << "\t    __        __" << endl;
        cout << "\t ********  ********" << endl;
        cout << "\t****____________****" << endl;
        cout << "\t****| Goodbye! |***" << endl;
        cout << "\t ***------------**" << endl;
        cout << "\t   *************" << endl;
        cout << "\t      *******" << endl;
        cout << "\t         *" << endl;
    }
};
#endif