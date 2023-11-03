#include "linked_list.cpp"
#ifndef _adjacency_list
#define _adjacency_list
using namespace std;

class Graph
{
    int n, m, _n;
    Don_list<int> *a;
    int *trongso;

public:
    Graph()
    {
        this->m = 0;
        this->n = 0;
        this->a = nullptr;
        this->trongso = nullptr;
    }
    Graph(int n, int _n, int m)
    {
        this->_n = _n;
        this->m = m;
        this->n = n;
        this->a = new Don_list<int>[n];
        this->trongso = new int[n * n];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            a[i].push_back(i);
            trongso[i * n + j++] = 0;
        }
    }
    Graph &operator=(const Graph &x)
    {
        delete[] this->a;
        delete[] this->trongso;
        this->_n = x._n;
        this->m = x.m;
        this->n = x.n;
        this->a = new Don_list<int>[x.n];
        this->trongso = new int[x.n * x.n];
        for (int i = 0; i < x.n; i++)
        {
            for (int j = 0; j < x.n; j++)
            {
                this->trongso[i * x.n + j] = x.trongso[i * x.n + j];
            }
            iter<int> temp = x.a[i].dau();
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
        delete[] trongso;
    }
    void add(int s, int d, int tso)
    {
        a[s].push_back(d);
        a[d].push_back(s);
        trongso[s * n + d] = trongso[d * n + s] = tso;
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
        x.a = new Don_list<int>[x.n];
        x.trongso = new int[x.n * x.n];
        for (int i = 0; i < x.n; i++)
        {
            x.a[i].push_back(i);
            x.trongso[i * x.n + j++] = 0;
        }
        for (int i = 0; i < x.m; i++)
        {
            x.add(tmp[i][0], tmp[i][1], tso[i]);
        }
        cout << "Doc thanh cong!\n";
        return cin;
    }
    friend istream &operator>>(istream &cin, Graph &x)
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
        x.a = new Don_list<int>[x.n];
        x.trongso = new int[x.n * x.n];
        for (int i = 0; i < x.n; i++)
        {
            x.a[i].push_back(i);
            x.trongso[i * x.n + j++] = 0;
        }
        for (int i = 0; i < x.m; i++)
        {
            x.add(tmp[i][0], tmp[i][1], tso[i]);
        }
        cout << "Doc thanh cong!\n";
        return cin;
    }
    friend ofstream &operator<<(ofstream &cout, const Graph &x)
    {
        int tmp[x.n * x.n] = {0};
        cout << "Số đỉnh: " << x._n << endl;
        for (int i = 0; i < x.n; i++)
        {
            iter<int> temp = x.a[i].dau();
            if (temp != nullptr)
            {
                cout << "Đỉnh " << x.a[i].front() << " kết nối với:\n";
                int j = x.a[i].front();
                while (temp != nullptr)
                {
                    int k = *temp;
                    if (!tmp[j * x.n + k])
                    {
                        tmp[j * x.n + k] = 1;
                        cout << "\tĐỉnh " << k << " có trọng số " << x.trongso[j * x.n + k] << endl;
                    }
                    temp++;
                }
                cout << endl;
            }
        }
        return cout;
    }
    friend ostream &operator<<(ostream &cout, const Graph &x)
    {
        int tmp[x.n * x.n] = {0};
        cout << "So dinh: " << x.n << endl;
        for (int i = 0; i < x.n; i++)
        {
            iter<int> temp = x.a[i].dau();
            if (temp != nullptr)
            {
                cout << "Dinh " << x.a[i].front() << " ket noi voi:\n";
                int j = x.a[i].front();
                while (temp != nullptr)
                {
                    int k = *temp;
                    if (!tmp[j * x.n + k])
                    {
                        tmp[j * x.n + k] = 1;
                        cout << "\tDinh " << k << " co trong so " << x.trongso[j * x.n + k] << endl;
                    }
                    temp++;
                }

                cout << endl;
            }
        }
        return cout;
    }
    void _dfs(int u, int t[])
    {
        t[u] = 1;
        iter<int> temp = a[u].dau();
        while (temp != nullptr)
        {
            int v = *temp;
            if (!t[v])
            {
                _dfs(v, t);
            }
            temp++;
        }
    }
    void DFS(int u, int t[])
    {
        cout << u << " ";
        t[u] = 1;
        iter<int> temp = a[u].dau();
        while (temp != nullptr)
        {
            int v = *temp;
            if (!t[v])
            {
                DFS(v, t);
            }
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
            iter<int> temp = a[k].dau();
            while (temp != nullptr)
            {
                int v = *temp;
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
        if (_dem_lien_thong() == 1)
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
                iter<int> temp = a[k].dau();
                while (temp != nullptr)
                {
                    int v = *temp;
                    if (!t[v])
                    {
                        c.push(v);
                    }
                    temp++;
                }
            }
        }
        else
            cout << "Do thi khong lien thong.\nHuy lenh BFS!\n";
    }
    void _DFS()
    {
        if (_dem_lien_thong() == 1)
        {
            int t[n + 1] = {0};
            DFS(1, t);
        }
        else
            cout << "Do thi khong lien thong.\nHuy lenh DFS!\n";
    }
    int _dem_lien_thong()
    {
        int t[n + 1] = {0}, res = 0;
        for (int i = 1; i < n; i++)
        {
            iter<int> temp = a[i].dau().getnode()->getNext();
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
        if (_dem_lien_thong() == 1)
        {
            cout << "Nhap dinh dau va cuoi: ";
            int dau, cuoi;
            cin >> dau >> cuoi;
            vector<int> d(n, INT_MAX), res(n);
            d[dau] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.push({0, dau});
            while (!q.empty())
            {
                pair<int, int> top = q.top();
                q.pop();
                int u = top.second;
                int kc = top.first;
                if (kc > d[u])
                    continue;
                iter<int> temp = a[u].dau();
                while (temp != nullptr)
                {
                    int v = *temp;
                    int w = trongso[u * n + v];
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
            cout << "Do thi khong lien thong.\nHuy lenh tim kiem!\n";
    }
};
#endif