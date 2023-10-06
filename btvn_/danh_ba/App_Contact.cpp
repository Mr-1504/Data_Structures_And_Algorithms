#include <bits/stdc++.h>
#include "addressbook.cpp"
using namespace std;
class app
{
    AddressBook a;

public:
    void home()
    {
        cout << "\n _______________^-^_______________\n";
        cout << " |             Danh ba           |\n";
        cout << " |                               |\n";
        cout << " |    1. Xem danh ba.            |\n";
        cout << " |    2. Them lien he moi.       |\n";
        cout << " |    3. Xoa lien he.            |\n";
        cout << " |    4. Tim kiem lien he.       |\n";
        cout << " |    5. Thoat chuong trinh.     |\n";
        cout << " |                               |\n";
        cout << " ---------------------------------\n";
        cout << "\nChon tac vu ban muon thuc hien: ";
        int x;
        cin >> x;
        cout << "\n";
        switch (x)
        {
        case 1:
            show();
            break;
        case 2:
            a.add_contact();
            break;
        case 3:
            a.erase();
            break;
        case 4:
            a.search();
            break;
        case 5:
            cout << " Nhac lai!!\n";
            return;
        default:
            cout << "Thao tac khong dung!\n";
        }
        home();
    }
    bool continue_app()
    {
        cout << "\nBan co muon thoat chuong trinh?\n";
        cout << "Nhap \"y\" de xac nhan hoac \"n\" de huy: ";
        char x;
        cin >> x;
        if (x == 'y')
            return true;
        else
            return false;
    }
    void show()
    {
        cout << "----------------------------------\n";
        if (a.size() == 0)
            cout << " Danh ba trong!\n";
        else
            a.list_contact();
        cout << "----------------------------------\n";
        cout << "\nNhap phim bat ky de quay lai: ";
        char x;
        cin >> x;
    }
    void run()
    {
        do
        {
            home();
        } while (!continue_app());
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