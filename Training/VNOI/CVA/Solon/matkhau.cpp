#include<bits/stdc++.h>
using namespace std;
typedef string bignum_str;
void in(bignum_str &a)
{
    cin>>a;
}
void out(bignum_str &a)
{
    cout<<a;
}
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
        res=char(c+'0')+res;
    }
    return res;
}
bignum_str cs(bignum_str n)
{
    bignum_str N,M;
    for(int i=0;i<n.size();i++)
    {
        M=n[i];
        N=cong(N,M);
    }
    return N;
}
int main()
{
    bignum_str n;
    in(n);
    cout<<cs(n);
}
