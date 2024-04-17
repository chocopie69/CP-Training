#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int t,n,q, p[SZ];

struct Edge
{
    int u,v;
    ll w;

    Edge(int _u = 0, int _v = 0, ll _w = 0) : u(_u), v(_v), w(_w) {}

    bool operator < (const Edge& other) const
    {
        return w < other.w;
    }
} e[SZ];

map<int, int> mp[SZ];
set<int> s[SZ];
ll ans[SZ];

struct DSU
{
    int lab[SZ];

    void init(int _n)
    {
        for(int i = 1; i <= _n; ++i)
        {
            lab[i] = -1;
        }
    }

    int get(int u)
    {
        return (lab[u] < 0) ? u : lab[u] = get(lab[u]);
    }

    void join(int u, int v, ll w)
    {
        if(lab[u] > lab[v]) swap(u, v);
        for(int x : s[v])
        {
            ans[x] += mp[u][x] * mp[v][x] * w;
            mp[u][x] += mp[v][x];
            s[u].insert(x);
        }
        lab[u] += lab[v];
        lab[v] = u;
    }
} dsu;

void solve()
{
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        cin >> p[i];
    }
    for(int i = 1; i < n; ++i)
    {
        ll w;
        cin >> w;
        e[i] = {p[i], i+1, w};
    }
    sort(e + 1, e + n);
    dsu.init(n);
    for(int i = 1; i <= q; ++i)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            ++mp[x][i];
            s[x].insert(i);
        }
    }
    for(int i = 1; i < n; ++i)
    {
        int u = dsu.get(e[i].u), v = dsu.get(e[i].v);
        dsu.join(u, v, e[i].w);
    }
    for(int i = 1; i <= q; ++i)
    {
        cout << ans[i] << " ";
        ans[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        s[i].clear();
        mp[i].clear();
    }
    //cout << '\n';
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        solve();
    }
}

