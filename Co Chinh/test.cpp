#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,n,m;
ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    ll res=binpow(a,b/2);
    if(b%2==0)
    {
        return (res%m*res%m)%m;
    }
    else return (((res%m*res%m)%m*a%m)%m);
}
ll Try(ll x,ll n)
{
    if(n==1)
    {
        return 1;
    }
    if(n%2==0)
    {
        return (Try((x%m*x%m)%m,n/2)*(x%m+1))%m;
    }
    else return (Try((x%m*x%m)%m,n/2)*(x%m+1))%m+binpow(x,n-1);
}
int main()
{
    //freopen("SEQUENCE.INP","r",stdin);
    //freopen("SEQUENCE.OUT","w",stdout);
    cin>>x>>n>>m;
    n++;
    cout<<Try(x,n);
}
