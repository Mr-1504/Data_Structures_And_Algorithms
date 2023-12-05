#include "linked_list.cpp"
#ifndef _adjacency_list
#define _adjacency_list
using namespace std;

class Graph
{
    int n, m, _n;
    Don_list<pair<int, float>> *a;

protected:
    bool confirm();

public:
    Graph()
    {
        this->m = 0;
        this->n = 0;
        this->a = nullptr;
    }
    Graph(int n, int _n, int m);
    Graph &operator=(const Graph &x);
    ~Graph()
    {
        delete[] a;
    }
    void add(int s, int d, int tso);
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
    void _dfs(int u, int t[]);
    void DFS(int u, int t[]);
    void _bfs(int u, int t[], int _t[], int &j, ofstream &output);
    void BFS();
    void _DFS();
    int _dem_lien_thong();
    void con(ofstream &output);
    void dijkstra();
    void input_Gr(ofstream &output);
};
Graph::Graph(int n, int _n, int m)
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
Graph &Graph::operator=(const Graph &x)
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
void Graph::add(int s, int d, int tso)
{
    a[s].push_back({d, tso});
    a[d].push_back({s, tso});
}
void Graph::_dfs(int u, int t[])
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
void Graph::DFS(int u, int t[])
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
void Graph::_bfs(int u, int t[], int _t[], int &j, ofstream &output)
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
            int w = (*temp).second;
            if (!t[v] && !_t[k * n + v])
            {
                if (cnt)
                {
                    output << "Đồ thị con thứ " << j << ":\n";
                    cout << "Do thi con thu " << j++ << ":\n";
                    cnt = false;
                }
                cout << "\t" << k << " " << v << " " << w << endl;
                output << "\t" << k << " " << v << " " << w << endl;
                c.push(v);
                _t[k * n + v] = 1;
            }
            temp++;
        }
    }
}
void Graph::BFS()
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
void Graph::_DFS()
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
int Graph::_dem_lien_thong()
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
void Graph::con(ofstream &output)
{
    output << "Danh sách đồ thị con:\n";
    cout << "\nDanh sach do thi con\n";
    int _t[n * n + 1] = {0}, t[n + 1] = {0}, j = 1;
    for (int i = 0; i < n; i++)
        if (!t[i])
            _bfs(i, t, _t, j, output);
}
void Graph::dijkstra()
{
    cout << "Nhap dinh dau: ";
    int dau, cuoi;
    cin >> dau;
    cout << "Nhap dinh cuoi: ";
    cin >> cuoi;
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
void Graph::input_Gr(ofstream &output)
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
        cout << "Nhap canh thu " << i + 1 << " va trong so: ";
        cin >> x >> y >> w;
        output << x << " " << y << " " << w << endl;
    }
}
bool Graph::confirm()
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
#endif