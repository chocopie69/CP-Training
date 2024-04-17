#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "LOCK"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,res = INFLL,a[SZ],b[SZ],c[SZ];

void swapArray()
{
    for(int i = 2; i <= n; i++)
    {
        c[i] = a[i-1];
    }
    c[1] = a[n];
    for(int i = 1; i <= n; i++)
    {
        a[i] = c[i];
    }
}

ll dis(ll x, ll y)
{
    return (x <= y ? y-x : k-x+y+1);
}

ll add(ll x, ll y)
{
    return (x+y > k ? (x+y-1) % k : x+y);
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(ll t = 0; t < n; t++)
    {
        ll cur = INFLL, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            cur = dis(c[i],b[i]);
            cnt = 0;
            for(int j = 1; j <= n; j++)
            {
                cnt += dis(add(c[j],cur),b[j]);
            }
            if(cnt+cur+t < res)
            {
                res = cnt+cur+t;
            }
        }
        swapArray();
    }
    cout << res;
}


