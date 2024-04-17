#include<bits/stdc++.h>
using namespace std;
typedef string bignum_str;
void ss(bignum_str &a,bignum_str &b)
{
    while(a.size()<b.size())
    {
        a='0'+a;
    }
    while(b.size()<a.size())
    {
        b='0'+b;
    }
}
bignum_str cong(bignum_str a,bignum_str b)
{
    ss(a,b);
    int c=0;
    bignum_str res;
    for(int i=a.size()-1;i>=0;i--)
    {
        int d=(a[i]-'0')+(b[i]-'0')+c;
        c=d/10;
        res=(char)(d%10+'0')+res;
    }
    if(c)
    {
        res='1'+res;
    }
    return res;
}
bignum_str fi(int n)
{
    if(n==0)
    {
        return "0";
    }
    if(n==1)
    {
        return "1";
    }
    bignum_str f0="0",f1="1",fN;
    for(int i=2;i<=n;i++)
    {
        fN=cong(f0,f1);
        f0=f1;
        f1=fN;
    }
    return fN;
}
int main()
{
    int n;
    cin>>n;
    cout<<fi(n);
}
