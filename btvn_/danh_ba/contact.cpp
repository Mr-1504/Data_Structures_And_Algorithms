#include <bits/stdc++.h>
#ifndef _lien_he_cpp
#define _lien_he_cpp
using namespace std;
class contact
{
    string name, email, number;

public:
    contact() {}
    contact(string name, string email, string number)
    {
        this->email = email;
        this->name = name;
        this->number = number;
    }
    friend istream &operator>>(istream &cin, contact &a)
    {
        cin.ignore(1);
        cout << "Nhap lien he moi:\n";
        cout << "\tHo ten: ";
        getline(cin, a.name);
        cout << "\tSo dien thoai: ";
        cin >> a.number;
        cout << "\tEmail: ";
        cin >> a.email;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, const contact a)
    {
        cout << "\tHo ten: " << a.name << endl;
        cout << "\tSo dien thoai: " << a.number << endl;
        cout << "\tEmail: " << a.email << endl;
        return cout;
    }
    string name_contact() { return name; }
    string number_phone() { return number; }
    string email_contact() { return email; }
};
#endif
