#include "qsort.cpp"
using namespace std;
int main()
{
    int n;
    char a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    q_sort(a, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}