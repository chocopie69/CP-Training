#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=1e5+5,MOD=1e9+11;
string s1,s2;
ll n,Hash1[maxN+1],power1[maxN+1],Hasht1[maxN+1],powert1[maxN+1],Hash2[maxN+1],power2[maxN+1],Hasht2[maxN+1],powert2[maxN+1],base1=331,base2=317;
ll get1(ll l,ll r)
{
    return (((Hash1[r]-Hash1[l-1]*power1[r-l+1])%MOD+MOD)%MOD);
}
ll gett1(ll l,ll r)
{
    return (((Hasht1[r]-Hasht1[l-1]*powert1[r-l+1])%MOD+MOD)%MOD);
}
ll get2(ll l,ll r)
{
    return (((Hash2[r]-Hash2[l-1]*power2[r-l+1])%MOD+MOD)%MOD);
}
ll gett2(ll l,ll r)
{
    return (((Hasht2[r]-Hasht2[l-1]*powert2[r-l+1])%MOD+MOD)%MOD);
}
map<ll,ll> mp, mp2;
bool check1(ll k)
{
    mp.clear();
    mp2.clear();
    ll l=1,r=k;
    while(l <= n/2)
    {
        mp[get1(l,r)]++;
        mp2[get2(l,r)]++;
        //cout<<l<<" "<<r<<'\n';
        l++;
        r++;
    }
    l=1,r=k;
    while(l <= n/2)
    {
        if(mp.find(gett1(l,r))!=mp.end() && mp2.find(gett2(l,r))!=mp2.end() )
        {
            return true;
        }
        l++;
        r++;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2;
    s1=s1+s1;
    s2=s2+s2;
    n=s1.size();
    s1=" "+s1;
    s2=" "+s2;
    //cout<<s1<<" "<<s2<<'\n';
    Hash1[0]=0;
    power1[0]=1;
    for(int i=1;i<=n;i++)
    {
        power1[i]=(power1[i-1]%MOD*base1)%MOD;
        Hash1[i]=(Hash1[i-1]%MOD*base1+int(s1[i]))%MOD;
    }
    powert1[0]=1;
    Hasht1[0]=0;
    for(int i=1;i<=n;i++)
    {
        powert1[i]=(powert1[i-1]%MOD*base1)%MOD;
        Hasht1[i]=(Hasht1[i-1]%MOD*base1+int(s2[i]))%MOD;
    }
    Hash2[0]=0;
    power2[0]=1;
    for(int i=1;i<=n;i++)
    {
        power2[i]=(power2[i-1]%MOD*base2)%MOD;
        Hash2[i]=(Hash2[i-1]%MOD*base2+int(s1[i]))%MOD;
    }
    powert2[0]=1;
    Hasht2[0]=0;
    for(int i=1;i<=n;i++)
    {
        powert2[i]=(powert2[i-1]%MOD*base2)%MOD;
        Hasht2[i]=(Hasht2[i-1]%MOD*base2+int(s2[i]))%MOD;
    }
    ll l=1,r=n/2,res=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        //cout<<mid<<" ";
        if(check1(mid))
        {
            res=max(res,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res;
}
