#include "danhsachke.cpp"
#ifndef _app_do_thi_
#define _app_do_thi_
using namespace std;

class app
{
    Graph a;
    bool cnt;
    string input, output, child;

protected:
    bool confirm();
    void home();
    void end_task();

public:
    app()
    {
        cnt = true;
        input = "input.txt";
        output = "output.txt";
        child = "child.txt";
    }
    void inputFile();
    void inputKeyBoard();
    void Input();
    void Output();
    void generateSubgraphs();
    void bfs();
    void dfs();
    void dijkstra();
    void run();
};
bool app::confirm()
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
    cout << "Ban da nhap sai qua nhieu lan. Thoat chuong trinh.\n\n";
    cin.get();
    return false;
}
void app::inputFile()
{
    system("cls");
    cout << "\n--------^-^--------\n";
    cout << "1. Nhap tu file goc \"input.txt\".\n";
    cout << "2. Nhap tu file khac.\n";
    int _n;
    cout << "Nhap lua chon: ";
    cin >> _n;
    system("cls");
    if (_n == 2)
    {
        cout << "Nhap ten file: ";
        string _temp;
        cin >> _temp;
        input = _temp;
        system("cls");
    }
    ifstream inp(input);
    if (!inp.is_open())
    {
        cout << "Khong the mo file.\n";
        cout << "--------------------\n";
        input = "input.txt";
        if (confirm())
            home();
        else
            return;
    }
    inp >> a;
    inp.close();
    cnt = false;
    cout << "--------------------\n";
    cout << endl;
    if (confirm())
        home();
    else
        return;
}
void app::inputKeyBoard()
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
        home();
    else
        return;
}
void app::Input()
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
        home();
    system("cls");
    cout << "\n--------^-^--------\n";
    cout << "1. Nhap tu file goc \"input.txt\".\n";
    cout << "2. Nhap tu file khac.\n";
    cout << "3. Nhap tu ban phim.\n";
    int _n;
    cout << "\nNhap lua chon: ";
    cin >> _n;
    system("cls");
    switch (_n)
    {
    case 1:
    {
        input = "input.txt";
        ifstream inp(input);
        inp >> a;
        inp.close();
        break;
    }
    case 2:
    {
        cout << "Nhap ten file: ";
        string _temp;
        cin >> _temp;
        input = _temp;
        system("cls");
        ifstream inp(input);
        if (!inp.is_open())
        {
            cout << "Khong the mo file.\n";
            cout << "--------------------\n";
            input = "input.txt";
            if (confirm())
                home();
            else
                return;
        }
        else
        {
            ifstream inp(input);
            inp >> a;
            inp.close();
        }
        break;
    }
    case 3:
    {
        cout << "Ban dang thao tac tren file \"" << input << "\", ban co doi file?\n";
        cout << "Nhap \"y\" de doi hoac \"n\" de tiep tuc: ";
        char _t;
        cin >> _t;
        system("cls");
        if (_t == 'y')
        {
            cout << "Nhap ten file: ";
            string _temp;
            cin >> _temp;
            input = _temp;
            system("cls");
            ifstream inp(input);
            if (!inp.is_open())
            {
                cout << "Khong the mo file.\n";
                cout << "--------------------\n";
                input = "input.txt";
                if (confirm())
                    home();
                else
                    return;
            }
        }
        ofstream out(input);
        a.input_Gr(out);
        out.close();
        ifstream inp(input);
        inp >> a;
        inp.close();
        cnt = false;
        break;
    }
    }
    cout << "\n--------------------------^-^------------------------------\n";
    cout << endl;
    if (confirm())
        home();
    else
        return;
}
void app::Output()
{
    system("cls");
    cout << "\n --------^-^--------\n";
    ofstream out(output);
    out << a;
    out.close();
    cout << "Tac vu thanh cong!\n";
    cout << "\n --------^-^--------\n";
    cout << endl;
    if (confirm())
        home();
    else
        return;
}
void app::generateSubgraphs()
{
    system("cls");
    cout << "\n--------------------------^-^------------------------------\n";
    ofstream ch(child);
    a.con(ch);
    cout << "Tac vu thanh cong!\n";
    cout << "\n--------------------------^-^------------------------------\n";
    cout << endl;
    if (confirm())
        home();
    else
        return;
}
void app::bfs()
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
        home();
    else
        return;
}
void app::dfs()
{
    system("cls");
    cout << "\n--------------------------^-^------------------------------\n";
    cout << "Ket qua: ";
    a._DFS();
    cout << "\n--------------------------^-^------------------------------\n";
    cout << endl;
    if (confirm())
        home();
    else
        return;
}
void app::dijkstra()
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
        home();
    else
        return;
}
void app::home()
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
        char n;
        cin >> n;
        switch (n)
        {
        case '1':
        {
            inputFile();
            break;
        }
        case '2':
        {
            inputKeyBoard();
            break;
        }
        case '3':
            return;
        default:
        {
            system("cls");
            cout << "\n --------^-^--------\n";
            cout << "Thao tac khong hop le!\n";
            cout << "\n-----------------------------------\n";
            cout << endl;
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
        char n;
        cin >> n;
        cout << endl;
        switch (n)
        {
        case '1':
        {
            Input();
            break;
        }
        case '2':
        {
            Output();
            break;
        }
        case '3':
        {
            generateSubgraphs();
            break;
        }
        case '4':
        {
            bfs();
            break;
        }
        case '5':
        {
            dfs();
            break;
        }
        case '6':
        {
            dijkstra();
            break;
        }
        case '7':
            return;
        default:
        {
            system("cls");
            cout << "\n--------------------------^-^------------------------------\n";
            cout << "Thao tac khong hop le!\n";
            cout << endl;
            if (confirm())
                home();
            else
                return;
            break;
        }
        }
    }
}
void app::end_task()
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
void app::run()
{
    home();
    end_task();
}
#endif