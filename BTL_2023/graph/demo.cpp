#include "danhsachke.cpp"
using namespace std;
int main(){
    adj_list a(4);
    a.add(0,1);
    a.add(0,2);
    a.add(0,3);
    a.add(1,2);
    a.out();
}