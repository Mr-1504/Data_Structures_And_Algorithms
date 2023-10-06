#include "linked_list.cpp"
using namespace std;
int main(){
    Don_list<int> a;
    cout<<a.size()<<endl;
    a.push_back(3);
    cout<<a.front()<<" "<<a.back();
}