#include "mytree.cpp"
using namespace std;
int main(){
    node<int> a;
    a.push(1);
    a.push(2);
    a.push(2);
    a.push(2);
    a.push(-1);
    a.print();
}