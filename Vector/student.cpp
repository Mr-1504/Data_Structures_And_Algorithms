#ifndef STUDENT_CPP
#include"conio.h"
#include"iostream"
using namespace std;
class Student
{
private:
	int masv;
	char hoten[30];
	char gioi[4];
public:
	int getmasv(){
		return masv;
	}
	friend istream & operator >>(istream &is, Student &s);
	friend ostream & operator <<(ostream &os, Student s);
};

istream & operator >>(istream &is, Student &s)
{
	 cout<<"\nNhap ma sv:";
	 is>>s.masv;
	 cout<<"Nhap ho va ten:";
	 is.ignore(1);
	 is.get(s.hoten,30);
	 cout<<"Nhap gioi tinh:";
	 is.ignore(1);
	 is.get(s.gioi,4);
	 return is;
}
ostream & operator <<(ostream &os, Student s)
{
	  os<<s.masv<<"\t"<<s.hoten<<"\t" <<s.gioi;
	 return os;
}
#endif

