#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LADDER"

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

int n,q, a[SZ], lo[SZ], hi[SZ], pre;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pre = 1;
    lo[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i-1])
        {
            pre = i;
        }
        lo[i] = pre;
    }
    pre = n;
    hi[n] = n;
    for(int i = n-1; i >= 1; i--)
    {
        if(a[i] > a[i+1])
        {
            pre = i;
        }
        hi[i] = pre;
    }
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        cout << (hi[u] >= lo[v] ? "Yes" : "No") << '\n';
    }
}
