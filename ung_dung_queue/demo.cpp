#include "queue_moi.cpp"
using namespace std;
int main(){
    queue_moi<int>a;
    a.push(5);
    a.push(6);
    a.front()=7;
    cout<<a.front()<<" "<<a.size()<<" "<<a.back();
}