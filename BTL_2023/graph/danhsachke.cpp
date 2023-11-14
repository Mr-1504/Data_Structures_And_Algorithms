#include "linked_list.cpp"
#ifndef _adjacency_list
#define _adjacency_list
using namespace std;

class Graph
{
    int n, m, _n;
    Don_list<pair<int, float>> *a;
    bool cnt = true;

public:
    Graph()
    {
        this->m = 0;
        this->n = 0;
        this->a = nullptr;
    }
    Graph(int n, int _n, int m)
    {
        this->_n = _n;
        this->m = m;
        this->n = n;
        this->a = new Don_list<pair<int, float>>[n];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            a[i].push_back({i, 0});
        }
    }
    Graph &operator=(const Graph &x)
    {
        delete[] this->a;
        this->_n = x._n;
        this->m = x.m;
        this->n = x.n;
        this->a = new Don_list<pair<int, float>>[x.n];
        for (int i = 0; i < x.n; i++)
        {
            iter<pair<int, float>> temp = x.a[i].dau();
            while (temp != nullptr)
            {
                this->a[i].push_back(*temp);
                temp++;
            }
        }
        return *this;
    }

    ~Graph()
    {
        delete[] a;
    }
    void add(int s, int d, int tso)
    {
        a[s].push_back({d, tso});
        a[d].push_back({s, tso});
    }
    friend ifstream &operator>>(ifstream &cin, Graph &x)
    {
        cin >> x._n >> x.m;
        int tmp[x.m][2], tso[x.m];
        for (int i = 0; i < x.m; i++)
        {
            cin >> tmp[i][0] >> tmp[i][1] >> tso[i];
            x.n = max(tmp[i][0], max(tmp[i][1], x.n));
        }

        x.n++;
        int j = 0;
        x.a = new Don_list<pair<int, float>>[x.n];
        for (int i = 0; i < x.n; i++)
        {
            x.a[i].push_back({i, 0});
        }
        for (int i = 0; i < x.m; i++)
        {
            x.add(tmp[i][0], tmp[i][1], tso[i]);
        }
        cout << "Doc thanh cong!\n";
        return cin;
    }
    // friend istream &operator>>(istream &cin, Graph &x)
    // {
    //     cin >> x._n >> x.m;
    //     int tmp[x.m][2], tso[x.m];
    //     for (int i = 0; i < x.m; i++)
    //     {
    //         cin >> tmp[i][0] >> tmp[i][1] >> tso[i];
    //         x.n = max(tmp[i][0], max(tmp[i][1], x.n));
    //     }

    //     x.n++;
    //     int j = 0;
    //     x.a = new Don_list<int>[x.n];
    //     x.trongso = new float[x.n * x.n];
    //     for (int i = 0; i < x.n; i++)
    //     {
    //         x.a[i].push_back(i);
    //         x.trongso[i * x.n + j++] = 0;
    //     }
    //     for (int i = 0; i < x.m; i++)
    //     {
    //         x.add(tmp[i][0], tmp[i][1], tso[i]);
    //     }
    //     cout << "Doc thanh cong!\n";
    //     return cin;
    // }
    friend ofstream &operator<<(ofstream &cout, const Graph &x)
    {
        int tmp[x.n * x.n] = {0};
        cout << "Số đỉnh: " << x._n << endl;
        for (int i = 0; i < x.n; i++)
        {
            iter<pair<int, float>> temp = x.a[i].dau();
            temp++;
            if (temp != nullptr)
            {
                cout << "Đỉnh " << x.a[i].front().first << " kết nối với:\n";
                int j = x.a[i].front().first;
                while (temp != nullptr)
                {
                    int k = (*temp).first;
                    if (!tmp[j * x.n + k])
                    {
                        tmp[j * x.n + k] = 1;
                        cout << "\tĐỉnh " << k << " có trọng số " << (*temp).second << endl;
                    }
                    temp++;
                }
                cout << endl;
            }
        }
        return cout;
    }
    // friend ostream &operator<<(ostream &cout, const Graph &x)
    // {
    //     int tmp[x.n * x.n] = {0};
    //     cout << "So dinh: " << x.n << endl;
    //     for (int i = 0; i < x.n; i++)
    //     {
    //         iter<int> temp = x.a[i].dau();
    //         if (temp != nullptr)
    //         {
    //             cout << "Dinh " << x.a[i].front() << " ket noi voi:\n";
    //             int j = x.a[i].front();
    //             while (temp != nullptr)
    //             {
    //                 int k = *temp;
    //                 if (!tmp[j * x.n + k])
    //                 {
    //                     tmp[j * x.n + k] = 1;
    //                     cout << "\tDinh " << k << " co trong so " << x.trongso[j * x.n + k] << endl;
    //                 }
    //                 temp++;
    //             }

    //             cout << endl;
    //         }
    //     }
    //     return cout;
    // }
    void _dfs(int u, int t[])
    {
        t[u] = 1;
        iter<pair<int, float>> temp = a[u].dau();
        while (temp != nullptr)
        {
            int v = (*temp).first;
            if (!t[v])
                _dfs(v, t);
            temp++;
        }
    }
    void DFS(int u, int t[])
    {
        cout << u << " ";
        t[u] = 1;
        iter<pair<int, float>> temp = a[u].dau();
        while (temp != nullptr)
        {
            int v = (*temp).first;
            if (!t[v])
                DFS(v, t);
            temp++;
        }
    }
    void _bfs(int u, int t[], int _t[], int &j, ofstream &output)
    {
        bool cnt = true;
        queue<int> c;
        c.push(u);
        while (!c.empty())
        {
            int k = c.front();
            c.pop();
            t[k] = 1;
            iter<pair<int, float>> temp = a[k].dau();
            while (temp != nullptr)
            {
                int v = (*temp).first;
                if (!t[v] && !_t[k * n + v])
                {
                    if (cnt)
                    {
                        output << "Do thi con thu " << j << endl;
                        cout << "Do thi con thu " << j++ << endl;
                        cnt = false;
                    }
                    cout << "\t" << k << " " << v << endl;
                    output << "\t" << k << " " << v << endl;
                    c.push(v);
                    _t[k * n + v] = 1;
                }
                temp++;
            }
        }
    }
    void BFS()
    {
        int t[n + 1] = {0};
        queue<int> c;
        c.push(1);
        while (!c.empty())
        {
            int k = c.front();
            c.pop();
            if (!t[k])
                cout << k << " ";
            t[k] = 1;
            iter<pair<int, float>> temp = a[k].dau();
            while (temp != nullptr)
            {
                int v = (*temp).first;
                if (!t[v])
                    c.push(v);
                temp++;
            }
        }
    }
    void _DFS()
    {
        if (_dem_lien_thong() == 1)
        {
            int t[n + 1] = {0};
            DFS(1, t);
            cout << "\nTac vu thanh cong!\n";
        }
        else
            cout << "Do thi khong lien thong.\nHuy lenh DFS!\n";
    }
    int _dem_lien_thong()
    {
        int t[n + 1] = {0}, res = 0;
        for (int i = 1; i < n; i++)
        {
            iter<pair<int, float>> temp = a[i].dau().getnode()->getNext();
            if (!t[i] && temp != nullptr)
            {
                res++;
                _dfs(i, t);
                cout << endl;
            }
        }
        return res;
    }
    void con(ofstream &output)
    {
        output << "\nDanh sach do thi con\n";
        cout << "\nDanh sach do thi con\n";
        int _t[n * n + 1] = {0}, t[n + 1] = {0}, j = 1;
        for (int i = 0; i < n; i++)
            if (!t[i])
                _bfs(i, t, _t, j, output);
    }
    void dijkstra()
    {
        cout << "Nhap dinh dau va cuoi: ";
        int dau, cuoi;
        cin >> dau >> cuoi;
        if (a[dau].dau() != nullptr && a[cuoi].dau() != nullptr)
        {
            vector<float> d(n, INT_MAX), res(n);
            d[dau] = 0;
            priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> q;
            q.push({0, dau});
            while (!q.empty())
            {
                pair<float, int> top = q.top();
                q.pop();
                int u = top.second;
                float kc = top.first;
                // if (kc > d[u])
                //     continue;
                iter<pair<int, float>> temp = a[u].dau();
                while (temp != nullptr)
                {
                    int v = (*temp).first;
                    float w = (*temp).second;
                    if (d[v] > d[u] + w)
                    {
                        res[v] = u;
                        d[v] = d[u] + w;
                        q.push({d[v], v});
                    }
                    temp++;
                }
            }
            cout << "Duong di ngan nhat tu dinh " << dau << " den dinh " << cuoi << " la: ";
            vector<int> _res;
            _res.push_back(cuoi);
            int k = res[cuoi];
            while (k != dau)
            {
                _res.push_back(k);
                k = res[k];
            }
            _res.push_back(dau);
            for (int i = _res.size() - 1; i >= 0; i--)
                cout << _res[i] << " ";
            cout << "\nKhoang cach giua hai dinh la: " << d[cuoi] << endl;
        }
        else
            cout << "Dinh dau hoac cuoi khong hop le!\n";
    }
    void input_Gr(ofstream &output)
    {
        cout << "Nhap so dinh: ";
        int n;
        cin >> n;
        output << n << " ";
        cout << "Nhap so canh: ";
        cin >> n;
        output << n << "\n";
        for (int i = 0; i < n; i++)
        {
            int x, y, w;
            cout << "Nhap cac canh va trong so: ";
            cin >> x >> y >> w;
            output << x << " " << y << " " << w << endl;
        }
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
        if (cnt)
        {
            cout << "\t---------------------^-^---------------------\n";
            cout << "\t|\t    Danh sach tac vu.               |\n";
            cout << "\t---------------------------------------------\n";
            cout << "\t|\t1. Nhap do thi tu file.             |\n";
            cout << "\t|\t2. Nhap moi file do thi tu ban phim.|\n";
            cout << "\t---------------------------------------------\n";
            cout << "Chon tac vu: ";
            int n;
            cin >> n;
            switch (n)
            {
            case 1:
            {
                cout << "\n--------^-^--------\n";
                ifstream inp(input);
                inp >> *this;
                inp.close();
                cnt = false;
                cout << "--------------------------------------\n";
                cout << endl;
                if (confirm())
                    home(input, output, child);
                else
                    return;
                break;
            }
            case 2:
            {
                cout << "\n--------^-^--------\n";
                ofstream out(input);
                input_Gr(out);
                out.close();
                ifstream inp(input);
                inp >> *this;
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
            default:
            {
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
            cout << "\t-------------------^-^-------------------\n";
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
                ofstream out(input);
                input_Gr(out);
                out.close();
                ifstream inp(input);
                inp >> *this;
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
                cout << "\n--------------------------^-^------------------------------\n";
                ofstream out(output);
                out << *this;
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
                cout << "\n--------------------------^-^------------------------------\n";
                ofstream ch(child);
                con(ch);
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
                cout << "\n--------------------------^-^------------------------------\n";
                if (_dem_lien_thong() == 1)
                {
                    cout << "Ket qua: ";
                    BFS();
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
                cout << "\n--------------------------^-^------------------------------\n";
                cout << "Ket qua: ";
                _DFS();
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
                cout << "\n--------------------------^-^------------------------------\n";
                if (_dem_lien_thong() == 1)
                {
                    dijkstra();
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