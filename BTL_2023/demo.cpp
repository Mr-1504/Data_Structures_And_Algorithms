#include "danh_sach_can_bo.cpp"
using namespace std;
int main() {
    list_cb a;
    a.create_list();
    a.display();
    a.search("truong phong");
    return 0;
}