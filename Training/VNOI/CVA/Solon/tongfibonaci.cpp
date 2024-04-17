#include<bits/stdc++.h>
using namespace std;
string x1,x2,x3,n;
string s[500];
vector<string> v;
int res=0;
int dem;
int nh(string a,string b)
{
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    if(a>b)
    {
        return 0;
    }
    return 1;
}
string cong(string a,string b)
{
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    int c=0;
    string res;
    for(int i=len-1;i>=0;i--)
    {
        int d=(a[i]-'0')+(b[i]-'0')+c;
        c=d/10;
        res=(char)(d%10+'0')+res;
    }
    if(c>0)
    {
        res='1'+res;
    }
    return res;
}
void xuli()
{
    x1="0";
    s[0]="0";
    x2="1";
    s[1]="1";
    x3=cong(x1,x2);
    dem=1;
    while(nh(x3,n))
    {
        dem++;
        s[dem]=x3;
        x1=x2;
        x2=x3;
        x3=cong(x1,x2);
    }
}
int lh(string a,string b)
{
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    if(a>b)
    {
        return 1;
    }
    return 0;
}
string tru(string a, string b) {
    int len;
    int lena=a.size(),lenb=b.size();
    if(lena>lenb)
    {
        len=lena;
    }
    else len=lenb;
    while(a.size()<len)
    {
        a='0'+a;
    }
    while(b.size()<len)
    {
        b='0'+b;
    }
    int carry = 0;
    string c= "";
    for (int i =len-1; i>=0; i--)
    {
        int t = (a[i] - 48) - (b[i]- 48) - carry;
        if (t<0)
        {
            carry = 1;
            t = t+10;
        }
        else carry= 0;
        c = char (t+48) + c;
    }
    while (c[0]== '0'&&c.size()>1) c.erase(0,1);
    return c;
}
void xl()
{
    string x=s[dem];
    while(n!="0")
    {
        n=tru(n,x);
        v.push_back(x);
        res++;
        while(lh(s[dem],n))
        {
            dem--;
        }
        x=s[dem];
    }
}
int main()
{
    getline(cin,n);
    xuli();
    xl();
    for(int i=res-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
