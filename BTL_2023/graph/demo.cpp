#include "danhsachke.cpp"
using namespace std;
int main()
{
    ifstream input("input.txt");
    Graph a;
    input >> a;
    // cin>>a;
    ofstream output("output.txt");
    output << a;
    // cout<<a;
    // a.dem_lien_thong();
    // a.BFS();
    a.con(output);
    a.dijkstra();
    cout << "end";
}