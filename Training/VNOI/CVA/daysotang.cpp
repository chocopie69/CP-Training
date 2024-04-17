#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back

const int SZ = 1e6, MOD = 1e9+7;
const ll INFLL = 2e18;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n,d, a[SZ], res = 0;

int main()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i-1]) continue;
        ll x = a[i-1] - a[i];
        a[i] += d*(x/d+1);
        res += x/d+1;
    }
    cout << res;
}
