#include <iostream>
#include <string.h>
using namespace std;
int my_strcmpi(string s, string t){
    int len1 = s.length(), len2 = t.length();
    int min_len = len1 < len2 ? len1 : len2;
    for(int i = 0; i < min_len; i++){
        if(tolower(s[i]) != tolower(t[i])){
            return tolower(s[i]) - tolower(t[i]);
        }
    }
    if(len1 < len2)
        return '\0' - t[min_len];
    else if(len1 > len2)
        return s[min_len] - '\0';
    else
        return 0;
}
int main() {
    string a = "minh";
    string b = "MINHh";
    const char* x = a.c_str();
    const char* y = b.c_str();

    if(!my_strcmpi(a,b)){
        cout << "1";
    }else cout <<0;

    return 0;
}
