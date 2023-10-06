#include <bits/stdc++.h>
#include "vector_moi.cpp"
#include "document.cpp"
#ifndef _thu_muc_cpp
#define _thu_muc_cpp
using namespace std;
class folder
{
    string name;
    bool temp = true;
    vector_moi<document> a;

public:
    friend istream &operator>>(istream &cin, folder &b)
    {
        cout << "Ten thu muc moi: ";
        cin.ignore(1);
        getline(cin, b.name);
        return cin;
    }
    friend ostream &operator<<(ostream &cout, folder &b)
    {
        if (b.a.sophantu() == 0)
        {
            cout << "Thu muc trong\n";
        }
        else
        {
            for (int i = 0; i < b.a.sophantu(); i++)
            {
                cout << i + 1 << ". " << b.a[i].name_doc() << endl;
            }
        }
        return cout;
    }
    void erase_doc()
    {
        cout << "Ten tai lieu muon xoa: ";
        string x;
        bool cnt = false;
        cin.ignore(1);
        getline(cin, x);
        for (int i = 0; i < a.sophantu(); i++)
        {
            if (x == a[i].name_doc())
            {
                a.xoa(i);
                cnt = true;
            }
        }
        if (cnt)
            cout << "Xoa thanh cong!\n";
        else
            cout << "Khong tim thay tai lieu can xoa\n";
    }
    bool out(){
        cout << "\n___________________________________________\n";
        cout << "\nBan muon thoat chuong trinh?\n";
        cout << "Nhap \"y\" de xac nhan, \"n\" de tu choi: ";
        char x;
        cin >> x;
        cout << "-------------------------------------------\n";
        if (x == 'y')
            return true;
        else
            return false;
    }
    string name_folder() { return name; }
    void access_doc()
    {
        cout << "\n___________________________________________\n";
        cout << "|           DANH SACH THU MUC             |\n";
        if (a.sophantu() == 0)
        {
            cout << "|\t____________________________      |\n";
            cout << "|\t|     Thu muc trong!       |      |\n";
            cout << "|\t----------------------------      |\n";
        }
        else
        {
            cout << "|\t____________________________      |\n";
            for (int i = 0; i < a.sophantu(); i++)
            {
                cout << "|\t|" << i + 1 << ". " << left << setw(22) << a[i].name_doc() << " |      |" << endl;
            }
            cout << "|\t----------------------------      |\n";
        }
        int cnt = 0;
        cout << "|\t                                  |\n";
        cout << "|\t____________________________      |\n";
        if (a.sophantu())
        {
            cnt++;
            cout << "|\t|" << cnt << ". Truy cap tai lieu  .   |      |\n";
        }
        cout << "|\t|" << cnt + 1 << ". Tao tai lieu moi.      |      |\n";
        cout << "|\t|" << cnt + 2 << ". Xoa tai lieu.          |      |\n";
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
                cout << "Truy cap tai lieu thu: ";
                int k;
                cin >> k;
                if (k < 1 || k > a.sophantu())
                {
                    cout << "So tai lieu khong hop le!\n";
                }
                else
                {
                    cout << a[k - 1];
                }
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            case 2:
            {
                document x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\tTao tai lieu thanh cong!\n";
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            case 3:
                erase_doc();
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            default:
                cout << "So tac vu khong hop le!\n";
                break;
            }
            cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
        }
        else
        {
            switch (n)
            {
            case 1:
            {
                document x;
                cin >> x;
                a.them_cuoi(x);
                cout << "\tTao tai lieu thanh cong!\n";
                cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
                break;
            }
            default:
                cout << "So tac vu khong hop le!\n";
                break;
            }
            cout << "\nNhap phim bat ky de quay lai: ";
                char y;
                cin >> y;
        }
        access_doc();
    }
    void home_folder()
    {
        do
        {
            access_doc();
        } while (!out());
        return;
    }
};
#endif