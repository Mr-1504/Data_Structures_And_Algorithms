#include "danh_sach_can_bo.cpp"
#ifndef HEADER_NAME
#define HEADER_NAME
using namespace std;

class app{
    list_cb a;
    bool cnt = true;

public:
    bool confirm()
    {
        int tmp = 0;
        while (tmp < 3)
        {
            cout << "Nhap y de quay lai hoac n de thoat: ";
            char t;
            cin >> t;
            if (t == 'y')
                return true;
            else if (t == 'n')
                return false;
            else
            {
                system("cls");
                cout << "\nThao tac khong hop le.\n";
                tmp++;
            }
        }
        cout << "Ban da nhap sai qua nhieu lan. Thoat chuong trinh.\n";
        return false;
    }
    void home()
    {
        system("cls");
        if (cnt)
        {
            cout << "\t-----------------^-^-----------------\n";
            cout << "\t|\tDanh sach can bo trong      |\n";
            cout << "\t-------------------------------------\n";
            cout << "\t|\t1. Tao moi danh sach        |\n";
            cout << "\t|\t2. Thoat chuong trinh.      |\n";
            cout << "\t-------------------------------------\n";
            char n;
            cout << "Chon tac vu mong muon: ";
            cin >> n;
            switch (n)
            {
            case '1':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cnt = a.create_list();
                cout << "--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '2':
                return;
            default:
            {
                cout << "Thao tac khong hop le!\n";
                if (confirm())
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
            cout << "\t|\t7. Sap xep danh sach.                             |\n";
            cout << "\t|\t8. Thoat chuong trinh.                            |\n";
            cout << "\t-----------------------------------------------------------\n";
            char n;
            cout << "Chon tac vu mong muon: ";
            cin >> n;
            switch (n)
            {
            case '1':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Luu y! Viec tao moi se xoa di danh sach dang co.\n";
                cout << "Nhap 'y' de xac nhan hoac 'n' de quay lai: ";
                cout << endl;
                char x;
                int tmp = 0;
                while (tmp < 3)
                {
                    cin >> x;
                    tmp++;
                    if(x == 'y' || x == 'n')
                        break;
                    if(tmp ==3 ) {
                        cout << "Nhap qua nhieu lan. Thoat chuong trinh.\n";
                        return;
                    }
                    cout << "Thao tac khong hop le. Nhap lai: ";
                }

                if (x == 'y')
                {
                    system("cls");
                    a.del();
                    a = Don_list<can_bo>();
                    cnt = a.create_list();
                    cout << "--------------------------^-^------------------------------\n";
                    cout << "Nhap 'y' de tro ve man hinh chinh hoac 'n' de thoat: ";
                    if (confirm())
                        home();
                    else
                        return;
                }
                else
                    home();
                break;
            }
            case '2':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                a.add();
                cout << "\n--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '3':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                a._display();
                cout << "\n--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '4':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                a.display();
                cout << "\n--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '5':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Nhap chuc vu can tim: ";
                string y;
                cin.ignore(1);
                getline(cin, y);
                a.search(y);
                cout << "\n\t--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '6':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Nhap he so luong va phong ban can can tim: ";
                string z;
                float y;
                cin >> y;
                cin.ignore(1);
                getline(cin, z);
                a.search(y, z);
                cout << "\n--------------------------^-^------------------------------\n";
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '7':
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Sap xep thanh cong!\n";
                a.sort();
                a._display();
                if (confirm())
                    home();
                else
                    return;
                break;
            }
            case '8':
                return;
            default:
            {
                cout << "Thao tac khong hop le!\n";
                if (confirm())
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
        system("cls");
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