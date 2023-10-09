#include "danhsachke.cpp"
using namespace std;
int main(){
    ifstream input("input.txt");
    int n;
    input>>n;
    adj_list a(n);
    input>>a;
    ofstream output("output.txt");
    output<<a;
    cout<<a;
    cout<<a.dem_lien_thong();
}