#include<bits/stdc++.h>
using namespace std;
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
string operator * (string a, string b) {
    int mul=0;
    string c;
    int rem=0;
    for (int i=b.length()-1;i>=0;i--) {
        string res;
        for (int j=a.length()-1;j>=0;j--) {
            int t=(b[i]-48)*(a[j]-48)+rem;
            rem=t/10;
            t=t%10;
            res=char(t+48)+res;
        }
        for (int i=0;i<mul;i++)
            res.push_back('0');
        mul++;
        c=c+res;
    }
    if (rem!=0) {
        c=char(rem+48)+c;
    }
    return c;
}
using namespace std;
int main() {
    string mn="2";
    int k;
    string p;
    cin>>k;
    cin>>p;
    string a[k+1];
    a[0]="1";
    a[1]="2";
    for (int i=2;i<=k;i++) {
        a[i]=a[i-1]*mn;
    }
    string up="0",down="0";
    string num="1";
    for (int i=k;i>=1;i--) {
        if (comp(p,a[i]-"1"-p)==-1) {
            string t=up;
            up=down;
            down=num+t;
            p=a[i-1]-"1"-p;
        } else {
            up=up+num;
            p=p-a[i-1];
        }
        num=num*mn;
    }
    string pl="1";
    up=up+pl;
    cout<<up;
}
