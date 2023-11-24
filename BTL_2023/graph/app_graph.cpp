#include "danhsachke.cpp"
#ifndef _app_do_thi_
#define _app_do_thi_
using namespace std;

class app{
    Graph a;
    bool cnt;
public:
    app(){
        cnt = true;
    }
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
                cout << "\nThao tac khong hop le.\n";
                tmp++;
            }
        }
        cout << "Ban da nhap sai qua nhieu lan. Thoat chuong trinh.\n";
        return false;
    }

    void home(string input = "input.txt", string output = "output.txt", string child = "child.txt")
    {
        system("cls");
        if (cnt)
        {
            cout << "\n\t---------------------^-^---------------------\n";
            cout << "\t|\t    Danh sach tac vu.               |\n";
            cout << "\t---------------------------------------------\n";
            cout << "\t|\t1. Nhap do thi tu file.             |\n";
            cout << "\t|\t2. Nhap moi file do thi tu ban phim.|\n";
            cout << "\t|\t3. Thoat.                           |\n";
            cout << "\t---------------------------------------------\n";
            cout << "Chon tac vu: ";
            int n;
            cin >> n;
            switch (n)
            {
            case 1:
            {
                system("cls");
                cout << "\n--------^-^--------\n";
                ifstream inp(input);
                inp >> a;
                inp.close();
                cnt = false;
                cout << "--------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 2:
            {
                system("cls");
                cout << "\n--------^-^--------\n";
                ofstream out(input);
                a.input_Gr(out);
                out.close();
                ifstream inp(input);
                inp >> a;
                inp.close();
                cnt = false;
                cout << "\n-----------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 3:
                return;
            default:
            {
                system("cls");
                cout << "\n --------^-^--------\n";
                cout << "Thao tac khong hop le!\n";
                cout << "\n-----------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            }
        }
        else
        {
            cout << "\n\t-------------------^-^-------------------\n";
            cout << "\t|\t     Danh sach tac vu.          |\n";
            cout << "\t-----------------------------------------\n";
            cout << "\t|\t1. Nhap vao do thi moi.         |\n";
            cout << "\t|\t2. Ghi do thi ra file.          |\n";
            cout << "\t|\t3. Tao do thi con.              |\n";
            cout << "\t|\t4. Duyet do thi theo chieu rong.|\n";
            cout << "\t|\t5. Duyet do thi theo chieu sau. |\n";
            cout << "\t|\t6. Tim duong di ngan nhat.      |\n";
            cout << "\t|\t7. Thoat.                       |\n";
            cout << "\t-----------------------------------------\n";
            cout << "Chon tac vu: ";
            int n;
            cin >> n;
            cout << endl;
            switch (n)
            {
            case 1:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                char t;
                cout << "Nhap vao do thi moi se xoa di do thi cu.\n";
                cout << "Nhap 'y' de tiep tuc hoac 'n' de quay lai: ";
                int tmp = 0;
                while (tmp < 3)
                {
                    cin >> t;
                    tmp++;
                    if (t == 'y' || t == 'n')
                        break;
                    if (tmp == 3)
                    {
                        cout << "Nhap qua nhieu lan. Thoat chuong trinh.\n";
                        return;
                    }
                    cout << "Thao tac khong hop le. Nhap lai: ";
                }
                if (t == 'n')
                    home(input, output, child);
                system("cls");
                ofstream out(input);
                a.input_Gr(out);
                out.close();
                ifstream inp(input);
                inp >> a;
                inp.close();
                cnt = false;
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 2:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                ofstream out(output);
                out << a;
                out.close();
                cout << "Tac vu thanh cong!\n";
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 3:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                ofstream ch(child);
                a.con(ch);
                cout << "Tac vu thanh cong!\n";
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 4:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                if (a._dem_lien_thong() == 1)
                {
                    cout << "Ket qua: ";
                    a.BFS();
                    cout << "\nTac vu thanh cong!\n";
                }
                else
                    cout << "Do thi khong lien thong.\nHuy lenh BFS!\n";
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 5:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Ket qua: ";
                a._DFS();
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 6:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                if (a._dem_lien_thong() == 1)
                {
                    a.dijkstra();
                    cout << "Tac vu thanh cong!\n";
                }
                else
                    cout << "Do thi khong lien thong.\nHuy lenh tim kiem!\n";
                cout << "\n--------------------------^-^------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 7:
                return;
            default:
            {
                system("cls");
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Thao tac khong hop le!\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
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