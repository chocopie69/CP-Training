#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    bool check=true;
    int dem = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] != '(' && s[i] != ')') check = false;
        else if(s[i] == '(') dem++;
        else if(s[i] == ')') dem--;
        if(dem < 0) break;
    }
    if(check)
    {
        if(dem == 0) cout << "DUNG";
        else cout << "KHONG DUNG";
    } else
    {
        cout << "KHONG HOP LE";
    }
}

