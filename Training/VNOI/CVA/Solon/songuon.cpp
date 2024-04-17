#include<bits/stdc++.h>
using namespace std;
string n,m,s,sum,nguon="0";
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
    for(int i=a.length()-1;i>=0;i--)
    {
        int d=(a[i]-'0')+(b[i]-'0')+c;
        c=d/10;
        res=(char)(d%10+'0')+res;
    }
    if(c>0)
    {
        res=(char)(c+48)+res;
    }
    return res;
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
    for (int i =a.length()-1; i>=0; i--)
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
string Tong(string s)
{
    string c="0",t;
    int n1=s.length();
    for(int i=0;i<n1;i++)
    {
        t=s[i];
        c=cong(c,t);
    }
    return c;
}
string xau(int k)
{
    string c="";
    while(k!=0)
    {
        c=(char)(k%10+48)+c;
        k/=10;
    }
    return c;
}
bool ss(string a,string b)
{
    int x1=a.size(),x2=b.size();
    if(x1==x2)
    {
        return a <= b;
    }
    return x1 < x2;
}
int main()
{
    cin>>m;
    int so=9*m.length()+1;
    n=tru(m,xau(so));
    if(ss(m,xau(so))) n = "0";
    while(ss(n,m))
    {
        s=Tong(n);
        sum=cong(s,n);
        if(m==sum)
        {
            nguon=n;
            break;
        }
        //cout << n << " " << s << " " << sum << '\n';
        n=cong(n,"1");
    }
    cout<<nguon;
}
