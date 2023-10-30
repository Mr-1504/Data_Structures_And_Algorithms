#include "can_bo.cpp"
#include "linked_list.cpp"
#ifndef _danh_sach_cpp
#define _danh_sach_cpp
using namespace std;
bool cnt = true;
class list_cb
{
    Don_list<can_bo> a;

public:
    list_cb() {}
    list_cb(Don_list<can_bo> a)
    {
        this->a = a;
    }
    bool create_list()
    {
        cout << "\nTao danh sach can bo\nLuu y nhap ma can bo nho hon 1 de dung!\n\n";
        int i = 0;
        bool x;
        while (1)
        {
            cout << "Nhap thong tin can bo thu " << ++i << endl;
            can_bo temp;
            x = temp.input();
            if (!x)
                break;
            a.push_back(temp);
        }
        if (i == 1 && !x)
            return true;
        else
            return false;
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
                int j = 0;
                for (iter<can_bo> i = a.dau(); i != nullptr; i++, j++)
                    if (j == n - 1)
                        a.insert(i.getnode(), temp);
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
                if (X.Ten() > Y.Ten() || (X.Ten() == Y.Ten() && X.Ho() > Y.Ho()))
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
    void _display()
    {
        sort();
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            can_bo temp = i.getnode()->getE();
            cout << ++j << ". " << temp << endl;
        }
        return;
    }
    void search(string cvu)
    {
        sort();
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
        sort();
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
    void home()
    {
        if (cnt)
        {
            cout << "\t-----------------^-^-----------------\n";
            cout << "\t|\tDanh sach can bo trong      |\n";
            cout << "\t-------------------------------------\n";
            cout << "\t|\t1. Tao moi danh sach        |\n";
            cout << "\t|\t2. Thoat chuong trinh.      |\n";
            cout << "\t-------------------------------------\n";
            int n;
            cout << "Chon tac vu mong muon: ";
            cin >> n;
            switch (n)
            {
            case 1:
            {
                cout << "\n--------------------------^-^------------------------------\n";
                cnt = create_list();
                cout << "\nTao moi hoan tat!\n\n";
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 2:
                return;
            default:
            {
                cout << "Thao tac khong hop le!\nBan co muon tiep tuc.\n'y' de tiep tuc hoac 'n' de tu choi: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            }
        }
        else
        {
            cout << "\t--------------------------^-^------------------------------\n";
            cout << "\t|\t1. Tao danh sach moi.                             |\n";
            cout << "\t|\t2. Them mot can bo moi.                           |\n";
            cout << "\t|\t3. Xem danh sach can bo.                          |\n";
            cout << "\t|\t4. Thong ke can bo co he so luong tren 4.4.       |\n";
            cout << "\t|\t5. Loc theo chuc vu.                              |\n";
            cout << "\t|\t6. Loc theo he so luong va phong ban.             |\n";
            cout << "\t|\t7. Thoat chuong trinh.                            |\n";
            cout << "\t-----------------------------------------------------------\n";
            int n;
            cout << "Chon tac vu mong muon: ";
            cin >> n;
            switch (n)
            {
            case 1:
            {
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Luu y! Viec tao moi se xoa di danh sach dang co.\n";
                cout << "Nhap 'y' de xac nhan hoac 'n' de quay lai: ";
                cout << endl;
                char x;
                cin >> x;
                if (x == 'y')
                {
                    cnt = create_list();
                    cout << "\nTao moi hoan tat!\n";
                    cout << "--------------------------^-^------------------------------\n";
                    cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                    cin >> x;
                    if (x == 'y')
                        home();
                    else
                        return;
                }else home();
                break;
            }
            case 2:
            {
                cout << "--------------------------^-^------------------------------\n";
                add();
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 3:
            {
                cout << "--------------------------^-^------------------------------\n";
                _display();
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 4:
            {
                cout << "--------------------------^-^------------------------------\n";
                display();
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 5:
            {
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap chuc vu can tim: ";
                string y;
                cin.ignore(1);
                getline(cin, y);
                search(y);
                cout << "\t--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 6:
            {
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap he so luong va phong ban can can tim: ";
                string z;
                float y;
                cin >> y;
                cin.ignore(1);
                getline(cin, z);
                search(y, z);
                cout << "--------------------------^-^------------------------------\n";
                cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            case 7:
                return;
            default:
            {
                cout << "Thao tac khong hop le!\nBan co muon tiep tuc.\n'y' de tiep tuc hoac 'n' de tu choi: ";
                char x;
                cin >> x;
                if (x == 'y')
                    home();
                else
                    return;
                break;
            }
            }
        }
    }
    void end_task()
    {
        cout << "\t\t    __        __" << endl;
        cout << "\t\t ********  ********" << endl;
        cout << "\t\t****____________****" << endl;
        cout << "\t\t****| Goodbye! |***" << endl;
        cout << "\t\t ***------------**" << endl;
        cout << "\t\t   *************" << endl;
        cout << "\t\t      *******" << endl;
        cout << "\t\t         *" << endl;
    }
};
#endif