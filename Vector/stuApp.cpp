#include "conio.h"
#include "stdio.h"
#include "iostream"
#include "myvector.cpp"
#include "student.cpp"
using namespace std;
class VectorApp // Lop ung dung lop vector va lop VectorItr
{
private:
	myvector<Student> v;

public:
	int menu();
	void run();
	void GetElement();
	void InsertElement();
	void RemoveElement();
	void ReplaceElement();
	void ListElement();
};
int VectorApp::menu()
{
	cout << "1.Them mot sinh vien moi";
	cout << "\n2.Xoa mot sinh vien";
	cout << "\n3.Thay the mot sinh vien";
	cout << "\n4. Lay thong tin mot sinh vien";
	cout << "\n5.In danh sach sinh vien";
	cout << "\n6.Ket thuc chuong trinh";
	cout << "\nChon chuc nang tu 1..6:";
	int n;
	cin >> n;
	return n;
}
void VectorApp::run()
{
	int ch;
	do
	{
		system("cls");
		ch = menu();
		system("cls");
		switch (ch)
		{
		case 1:
			InsertElement();
			break;
		case 2:
			RemoveElement();
			break;
		case 3:
			ReplaceElement();
			break;
		case 4:
			GetElement();
			break;
		case 5:
			ListElement();
			break;
		}
		getch();
	} while (ch != 6);
}
void VectorApp::InsertElement()
{
	Student x;
	int r;
	cout << "Nhap thong tin cua sinh vien:";
	cin >> x;
	cout << "Vi tri chen:";
	cin >> r;
	v.insert(r, x);
	cout << "Chen phan tu thanh cong!";
}
void VectorApp::RemoveElement()
{
	myvector<Student>::iterator it;
	int ma;
	cout << "Nhap ma cua sinh vien can xoa bo:";
	cin >> ma;
	int k = 0;
	bool found = false;
	while (k < v.size() && found == false)
		if (v[k].getmasv() == ma)
			found = true;
		else
			k++;
	if (found)
	{
		v.erase(k);
		cout << "Phan tu bi xoa di :" << v[k];
	}
	else
		cout << "Khong tim thay sinh vien can xoa";
}
void VectorApp::ReplaceElement()
{
	int ma;
	Student x;
	cout << "Nhap ma cua sinh vien can thay the:";
	cin >> ma;
	int k = 0;
	bool found = false;
	while (k < v.size() && found == false)
		if (v[k].getmasv() == ma)
			found = true;
		else
			k++;
	if (found)
	{
		cout << "Nhap thong tin can thay the:";
		cin >> x;
		v[k] = x;
	}
	else
		cout << "Khong tim thay sinh vien co ma " << ma;
}
void VectorApp::GetElement()
{
	myvector<Student>::iterator it;
	int ma;
	cout << "Nhap ma cua sinh vien :";
	cin >> ma;
	int k = 0;
	bool found = false;
	while (k < v.size() && found == false)
		if (v[k].getmasv() == ma)
			found = true;
		else
			k++;
	if (found)
	{
		cout << "Thong tin sinh vien :" << v[k];
	}
	else
		cout << "Khong tim thay sinh vien";
}
void VectorApp::ListElement()
{
	myvector<Student>::iterator it;
	cout << "Danh sach cac sinh vien:\n";
	it = v.begin();
	while (it != v.end())
	{
		cout << *it;
		it++;
	}
}
