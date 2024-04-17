#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
#define ll long long
const ll MOD = 1e6;
ll n,b[MAX],f[MAX],fk1[MAX],res = 1;
int main()
{
    cin>>n;
    ll tong = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        tong += b[i];
    }
    //sort(b+1,b+n+1);
    f[0]=0;
    ll k=tong/2;
    for(int i=1;i<=k;i++)
    {
        f[i]=INT_MAX;
        for(int j=1;j<=n;j++)
        {
            if(b[j]<=i&&f[i-b[j]]<j)
            {
                f[i]=j;
                break;
            }
        }
    }
    while(f[k] == INT_MAX) k--;
    cout << abs(tong-k-k) << '\n';
    fk1[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = k; j >= b[i]; j-- )
        {
            if(b[i] <= j) fk1[j] = (fk1[j] + fk1[j-b[i]]) % MOD;
        }
    }
    cout << fk1[k];
}
