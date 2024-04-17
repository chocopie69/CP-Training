#include<bits/stdc++.h>
using namespace std;
string operator + (string a, string b) {
    string res;
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)+(b[i]-48)+rem;
        rem=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if (rem!=0) {
        res=char(rem+48)+res;
    }
    return res;
}
string operator - (string a, string b) {
    string res;
    if (a==b)
        return "0";
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]+48)-(b[i]+48)-rem;
        if (t<0) {
            rem=1;
            t+=10;
        } else {
            rem=0;
        }
        res=char(t+48)+res;
    }
    while (res[0]=='0')
        res.erase(0,1);
    return res;
}
int comp (string a, string b) {
    if (a.length()>b.length())
        return 1;
    if (a.length()<b.length())
        return -1;
    for (int i=0;i<a.length();i++) {
        if (a[i]>b[i]) {
            return 1;
        } else if (a[i]<b[i]) {
            return -1;
        }
    }
    return 0;
}
int main() {
    string a,b;
    cin>>a>>b;
    if (a[0]!='-'&&b[0]!='-')
        cout<<a+b;
    else if (a[0]=='-'&&b[0]=='-') {
        a.erase(0,1);
        b.erase(0,1);
        cout<<'-'<<a+b;
    }
    else {
        if (a[0]=='-') {
            a.erase(0,1);
            if (comp(a,b)==1) {
                cout<<'-'<<a-b;
            } else if (comp(a,b)==-1) {
                cout<<b-a;
            } else {
                cout<<'0';
            }
        } else {
            b.erase(0,1);
            if (comp(a,b)==0) {
                cout<<'0';
            } else if (comp(a,b)==1) {
                cout<<a-b;
            } else {
                cout<<'-'<<b-a;
            }
        }
    }
}
