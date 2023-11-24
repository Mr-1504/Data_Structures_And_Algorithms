#include "can_bo.cpp"
#include "linked_list.cpp"
#ifndef _danh_sach_cpp
#define _danh_sach_cpp
using namespace std;

// int _cmp(string s, string t)
// {
//     int len1 = s.length(), len2 = t.length();
//     int min_len = len1 < len2 ? len1 : len2;
//     for (int i = 0; i < min_len; i++)
//     {
//         if (tolower(s[i]) != tolower(t[i]))
//         {
//             return tolower(s[i]) - tolower(t[i]);
//         }
//     }
//     if (len1 < len2)
//         return '\0' - t[min_len];
//     else if (len1 > len2)
//         return s[min_len] - '\0';
//     else
//         return 0;
// }
class list_cb
{
    Don_list<can_bo> a;

public:
    list_cb() {}
    list_cb(Don_list<can_bo> a)
    {
        this->a = a;
    }
    bool filter(can_bo x)
    {
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            if ((*i) == x)
            {
                cout << "Can bo vua nhap da co trong danh sach!\n";
                return false;
            }
            if ((*i).ma_can_bo() == x.ma_can_bo())
            {
                cout << "Ma can bo da ton tai!\n";
                return false;
            }
        }
        return true;
    }
    bool create_list()
    {
        cout << "\nTao danh sach can bo\nLuu y nhap ma can bo nho hon 1 de dung!\n\n";
        int i = 0, _t = 0;
        bool x;
        while (1)
        {
            system("cls");
            cout << "Nhap thong tin can bo thu " << ++i << endl;
            can_bo temp;
            x = temp.input();
            if (!filter(temp))
            {
                cout << "Ban co muon nhap lai?\n";
                cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                char t;
                cin.ignore();
                cin >> t;
                while (t != 'y' && t != 'n')
                {
                    if (_t == 2)
                        break;
                    _t++;
                    system("cls");
                    cout << "Khong hop le, vui long nhap lai.\n";
                    cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                    cin.ignore();
                    cin >> t;
                }
                if (t == 'y')
                {
                    i--;
                    continue;
                }
                else
                    x = false;
            }
            if (!x)
                break;
            a.push_back(temp);
        }
        system("cls");
        if (i == 1 && !x)
        {
            if (_t == 2)
                cout << "Ban da nhap sai qua nhieu lan!\nThoat tac vu nhap.\n";
            else
                cout << "Huy lenh nhap!\n";

            return true;
        }
        else
        {
            if (_t == 2)
                cout << "Ban da nhap sai qua nhieu lan!\nThoat tac vu nhap.\n";
            else
                cout << "\nTao moi hoan tat!\n";
            return false;
        }
    }
    void add()
    {
        cout << "Hien tai danh sach co " << a.size() << " can bo.\n";
        cout << "Ban muon chon vi tri se them?\n";
        cout << "\t1. Chon vi tri.\n";
        cout << "\t2. Khong chon\n";
        char t;
        cout << "Tac vu: ";
        cin.ignore();
        cin >> t;
        switch (t)
        {
        case '1':
        {
            cout << "\tChon vi tri muon them: ";
            int n, _t = 0;
            cin >> n;
            while (n < 1 || n > a.size() + 1)
            {
                system("cls");
                if (_t == 2)
                {
                    cout << "Nhap sai qua nhieu lan, thoat tac vu.\n";
                    return;
                }
                _t++;
                cout << "Khong hop le, vui long nhap lai: ";
                cin >> n;
            }
            system("cls");
            can_bo temp;
            cout << "Nhap thong tin can bo can them\n";
            cin >> temp;
            system("cls");
            while (!filter(temp))
            {
                _t = 0;
                cout << "Ban co muon nhap lai?\n";
                cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                cin.ignore();
                char x;
                cin >> x;

                while (x != 'y' && x != 'n')
                {
                    if (_t == 2)
                    {
                        cout << "Nhap sai qua nhieu lan. Thoat tac vu!\n";
                        return;
                    }
                    _t++;
                    system("cls");
                    cout << "Khong hop le, vui long nhap lai.\n";
                    cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                    cin.ignore();
                    cin >> x;
                }
                system("cls");
                if (x == 'y')
                {
                    cout << "Nhap thong tin can bo can them\n";
                    cin >> temp;
                    system("cls");
                    continue;
                }
                else
                    return;
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
        }
        case '2':
        {
            system("cls");
            cout << "Nhap thong tin can bo can them\n";
            can_bo temp;
            cin >> temp;
            system("cls");
            int _t = 0;
            while (!filter(temp))
            {
                _t = 0;
                cout << "Ban co muon nhap lai?\n";
                cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                char x;
                cin.ignore();
                cin >> x;

                while (x != 'y' && x != 'n')
                {
                    if (_t == 2)
                        break;
                    _t++;
                    system("cls");
                    cout << "Khong hop le, vui long nhap lai.\n";
                    cout << "Nhap 'y' de nhap lai hoac 'n' de dung: ";
                    cin.ignore();
                    cin >> x;
                }
                system("cls");
                if (x == 'y')
                {
                    cin >> temp;
                    system("cls");
                    continue;
                }
                else
                    return;
                ;
                a.push_back(temp);
                break;
            }
        }
        default:
            cout << "\tThao tac khong hop le!\n";
            break;
        }
    }
    void del()
    {
        a.~Don_list();
    }
    void sort()
    {
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            for (iter<can_bo> j = i; j != nullptr; j++)
            {
                can_bo X = *i;
                can_bo Y = *j;
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
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            if ((*i).he_so_luong() >= 4.4)
            {
                if (!j)
                    cout << "Danh sach cac can bo co he so luong tren 4.4 la:\n";
                cout << ++j << ". " << *i << endl;
            }
        }
        if (!j)
            cout << "Khong co can bo co he so luong tren 4.4\n";
        return;
    }
    void _display()
    {
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            cout << ++j << ". " << *i << endl;
        }
        return;
    }
    void search(string cvu)
    {
        int j = 0;
        for (iter<can_bo> i = a.dau(); i != nullptr; i++)
        {
            if (!_cmp((*i).chuc_vu(), cvu))
            {
                if (!j)
                    cout << "Danh sach cac can bo co chuc vu " << cvu << " la" << endl;
                cout << ++j << ". " << *i << endl;
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
            if ((*i).he_so_luong() == hsl && !_cmp((*i).phong_ban(), phong))
            {
                if (!j)
                    cout << "Danh sach cac can bo co he so luong tren 4.4 o phong ban " << phong << "la:\n";
                cout << ++j << ". " << *i << endl;
            }
        }
        if (!j)
            cout << "Khong co can bo co he so luong " << hsl << " o phong " << phong << endl;
        return;
    }
};
#endif