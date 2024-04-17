#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7+5;
#define ll long long
ll n,b[MAX],f[MAX];
vector<int> res;
int main()
{
    cin>>n;
    ll tong = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        tong += b[i];
    }
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
    while(k > 0)
    {
        res.push_back(f[k]);
        k -= b[f[k]];
    }
    for(int i = res.size()-1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
}
