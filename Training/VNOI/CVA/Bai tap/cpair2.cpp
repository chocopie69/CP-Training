#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7+5;
#define TASKNAME "CPAIRS"
long long n,p,k,a[MAX];
map<long long,long long> mp,mp1;
int main()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
     cin>>n>>p>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[(a[i]%p)*((a[i]%p*a[i]%p*a[i]%p-k%p)%p+p)%p]++;
        mp1[a[i]]++;
    }
    long long dem=0,dem1=0;
    for(int i=1;i<=n;i++)
    {
        int res=(a[i]%p)*((a[i]%p*a[i]%p*a[i]%p-k%p)+p)%p;
        mp[res]--;
        dem+=max(0ll,mp[res]);
    }
    while(mp1[0]>0)
    {
        mp1[0]--;
        dem1+=mp1[0];
    }
    cout<<dem-dem1;
}
