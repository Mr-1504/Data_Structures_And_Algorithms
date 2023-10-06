#include "stack.cpp"
using namespace std;
int main()
{
    stack_moi<int> a;
    cout << a.top() << " " << a.size() << endl;
    a.push(1);
    a.push(2);
    cout << a.top() << " " << a.size() << endl;
    a.pop();
    cout << a.top() << " " << a.size() << endl;
}