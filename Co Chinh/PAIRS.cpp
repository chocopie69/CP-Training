#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PAIRS"

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

ll sum(ll x)
{
    return x*(x+1)/2;
}

struct DSU
{
    ll par[SZ], s[SZ], cnt[SZ], res = 0;

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
            cnt[i] = 1;
        }
    }

    ll get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        if(s[u] < s[v]) swap(u,v);
        if(u != v)
        {
            par[v] = u;
            //res -= (sum(s[u]-1) + sum(s[v]-1));
            res += s[u]*s[v];
            s[u] +=  s[v];
            //res += s[u]*s[v];
        }
        cout << res << '\n';
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

int n,m,u,v;

int main()
{
    init();
    cin >> n >> m;
    dsu.init(n);
    while(m--)
    {
        cin >> u >> v;
        dsu.join(u,v);
    }
}
