#include "linked_list.cpp"
#ifndef _adjacency_list
#define _adjacency_list
using namespace std;
class adj_list
{
    int n;
    Don_list<int> *a;
    int *trongso;

public:
    adj_list(int n)
    {
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
    ~adj_list()
    {
        delete[] a;
        delete[] trongso;
    }
    // int &operator [](int k){
    //     return a[k].front();
    // }
    void add(int s, int d, int tso)
    {
        a[s].push_back(d);
        a[d].push_back(s);
        trongso[s * n + d] = trongso[d * n + s] = tso;
    }
    friend ifstream &operator>>(ifstream &cin, adj_list &x)
    {
        for (int i = 0; i < x.n; i++)
        {
            int s, d, tso;
            cin >> s >> d >> tso;
            x.add(s, d, tso);
        }
        cout << "Doc thanh cong!\n";
        return cin;
    }
    friend istream &operator>>(istream &cin, adj_list &x)
    {
        for (int i = 0; i < x.n; i++)
        {
            int s, d, tso;
            cin >> s >> d >> tso;
            x.add(s, d, tso);
        }
        cout << "Doc thanh cong!\n";
        return cin;
    }
    friend ofstream &operator<<(ofstream &cout, const adj_list &x)
    {
        cout << "Số đỉnh: " << x.n << endl;
        for (int i = 0; i < x.n; i++)
        {
            cout << "Đỉnh " << x.a[i].front() << " kết nối với:\n";
            node<int> *temp = x.a[i].dau().getnode()->getNext();
            int j = x.a[i].front();
            while (temp != nullptr)
            {
                int k = temp->getE();
                cout << "\tĐỉnh " << k << " có trọng số " << x.trongso[j * x.n + k] << endl;
                temp = temp->getNext();
            }
        }
        cout << endl;
        return cout;
    }
    friend ostream &operator<<(ostream &cout, const adj_list &x)
    {
        cout << "So dinh: " << x.n << endl;
        for (int i = 0; i < x.n; i++)
        {
            int j = x.a[i].front();
            cout << "Dinh " << j << " ket noi voi:\n";
            node<int> *temp = x.a[i].dau().getnode()->getNext();
            while (temp != nullptr)
            {
                int k = temp->getE();
                cout << "\tDinh " << k << " co trong so " << x.trongso[k * x.n + j] << endl;
                temp = temp->getNext();
            }
            cout << endl;
        }
        return cout;
    }
    void dfs(int u, int t[])
    {
        if (!t[u])
        {
            t[u] = 1;
            node<int> *temp = a[u].dau().getnode()->getNext();
            while (temp != nullptr)
            {
                int v = temp->getE();
                if (!t[v])
                    dfs(v, t);
                temp = temp->getNext();
            }
        }
    }
    int dem_lien_thong()
    {
        int test[n] = {0};
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!test[i])
            {
                res++;
                dfs(i, test);
            }
        }
        return res;
    }
};
#endif