#include <bits/stdc++.h>
#ifndef _can_bo_cpp
#define _can_bo_cpp
using namespace std;
class can_bo
{
    int id;
    string ho, ten, ban, cvu;
    float hsl;
    long long luong;
    void tinh_luong()
    {
        luong = hsl * 1350000;
    }

public:
    can_bo(int id = 0, string ho = "", string ten = "", string ban = "", string cvu = "", float hsl = 0)
    {
        this->id = id;
        this->ho = ho;
        this->ten = ten;
        this->ban = ban;
        this->cvu = cvu;
        this->hsl = hsl;
        tinh_luong();
    }
    can_bo(const can_bo &x)
    {
        this->id = x.id;
        this->ho = x.ho;
        this->ten = x.ten;
        this->ban = x.ban;
        this->cvu = x.cvu;
        this->hsl = x.hsl;
        tinh_luong();
    }
    can_bo &operator=(const can_bo &x)
    {
        this->id = x.id;
        this->ho = x.ho;
        this->ten = x.ten;
        this->ban = x.ban;
        this->cvu = x.cvu;
        this->hsl = x.hsl;
        tinh_luong();
        return *this;
    }
    bool input()
    {
        cout << "\tNhap ma can bo: ";
        cin >> id;
        if (id <= 0)
            return false;
        cin.ignore(1);
        cout << "\tNhap ho ten can bo: ";
        string temp;
        getline(cin, temp);
        bool test = false;
        for (int i = temp.length() - 1; i >= 0; i--)
        {
            if (temp[i] == ' ')
            {
                ho = temp.substr(0, i);
                ten = temp.substr(i + 1, temp.length() - i);
                test = true;
                break;
            }
            if (!test)
            {
                ten = temp;
                ho = "";
            }
        }
        cout << "\tPhong ban: ";
        getline(cin, ban);
        cout << "\tChuc vu: ";
        getline(cin, cvu);
        cout << "\tHe so luong: ";
        cin >> hsl;
        tinh_luong();
        return true;
    }
    friend istream &operator>>(istream &cin, can_bo &x)
    {
        cout << "\tNhap ma can bo: ";
        cin >> x.id;
        cin.ignore(1);
        cout << "\tNhap ho ten can bo: ";
        string temp;
        getline(cin, temp);
        bool test = false;
        for (int i = temp.length() - 1; i >= 0; i--)
        {
            if (temp[i] == ' ')
            {
                x.ho = temp.substr(0, i);
                x.ten = temp.substr(i + 1, temp.length() - i);
                test = true;
                break;
            }
            if (!test)
            {
                x.ten = temp;
                x.ho = "";
            }
        }
        cout << "\tPhong ban: ";
        getline(cin, x.ban);
        cout << "\tChuc vu: ";
        getline(cin, x.cvu);
        cout << "\tHe so luong: ";
        cin >> x.hsl;
        x.tinh_luong();
        return cin;
    }
    friend ostream &operator<<(ostream &cout, const can_bo &x)
    {
        cout << "\tMa can bo: " << x.id << endl;
        cout << "\tHo ten can bo: " << x.ho << " " << x.ten << endl;
        cout << "\tPhong ban: " << x.ban << endl;
        cout << "\tChuc vu: " << x.cvu << endl;
        cout << "\tHe so luong: " << x.hsl << endl;
        cout << "\tLuong: " << x.luong << endl;
        return cout;
    }
    int ma_can_bo() { return id; }
    string ho_ten()
    {
        string temp = ho + " " + ten;
        return temp;
    }
    string Ho() { return ho; }
    string Ten() { return ten; }
    string phong_ban() { return ban; }
    string chuc_vu() { return cvu; }
    float he_so_luong() { return hsl; }
    long long Luong() { return luong; }
};
#endif