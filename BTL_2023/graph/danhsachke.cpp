#include "linked_list.cpp"
#ifndef _adjacency_list
#define _adjacency_list
using namespace std;
class adj_list
{
    int n;
    Don_list<int> *a;
    int trongso;
public:
    adj_list(int n)
    {
        this->n = n;
        this->a = new Don_list<int>[n];
        for(int i=0;i<n;i++){
            a[i].push_back(i);
        }
    }
    void add(int s, int d)
    {
        a[s].push_back(d);
        a[d].push_back(s);
    }
    void out()
    {
        
        for (int i = 0; i < n; i++)
        {
            cout<<"dinh "<<a[i].front()<<" ket noi: ";
            node<int> *temp = a[i].dau().getnode()->getNext();
            while (temp!=nullptr)
            {
                cout<<temp->getE()<<" ";
                temp= temp->getNext();
            }
            cout << endl;
        }
    }

};
#endif