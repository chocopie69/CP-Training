#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "TUNNEL"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,s,t,u,v,h,d;

struct Edge
{
    ll v, h, d;
    Edge(ll _v, ll _h, ll _d)
    {
        v = _v;
        h = _h;
        d = _d;
    }
};

int main()
{
    init();
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> h >> d;
        adj[u].push_back({v,h,d});
        adj[v].push_back({u,h,d});
    }
    ll lo = 0, hi = 1e9+2, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) /2;
        if(check(mid))
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
}
