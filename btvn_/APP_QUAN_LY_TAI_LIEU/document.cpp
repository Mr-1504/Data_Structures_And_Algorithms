#include <bits/stdc++.h>
#ifndef _tai_lieu_cpp
#define _tai_lieu_cpp
using namespace std;
class document
{
    string name, description, writer, format;
    int year;

public:
    document() {}
    document(string name, string description, string writer, string format, int year)
    {
        this->name = name;
        this->description = description;
        this->writer = writer;
        this->format = format;
        this->year = year;
    }
    friend istream &operator>>(istream &cin, document &a)
    {
        cin.ignore(1);
        cout << "\tTen tai lieu: ";
        getline(cin, a.name);
        cout << "\tMo ta: ";
        getline(cin, a.description);
        cout << "\tTac gia: ";
        getline(cin, a.writer);
        cout << "\tDinh dang: ";
        cin >> a.format;
        cout << "\tNam xuat ban: ";
        cin >> a.year;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, const document a)
    {
        cout << "\tTen tai lieu: " << a.name << endl;
        cout << "\tMo ta: " << a.description << endl;
        cout << "\tTac gia: " << a.writer << endl;
        cout << "\tDinh dang: " << a.format << endl;
        cout << "\tNam xuat ban: " << a.year << endl;
        return cout;
    }
    string name_doc() { return name; }
    string descrip_doc() { return description; }
    string writer_doc() { return writer; }
    string format_doc() { return format; }
    int year_doc() { return year; }
};
#endif