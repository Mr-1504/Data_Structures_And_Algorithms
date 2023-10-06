#include "linked_list.cpp"
using namespace std;
int main()
{
    Don_list<int> a;
    cout << a.size() << endl;
    int n;
    cin >> n;
    a.push_back(n);
    cout << a.size() << endl;
    a.push_back(5);
    cout << a.front() << " " << a.back();
}