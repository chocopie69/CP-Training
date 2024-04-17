#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m,q, cnt[SZ], color[SZ], res[SZ];

struct DSU
{
    ll par[SZ], s[SZ];

    map<int,int> mp[SZ];

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
            mp[i][color[i]] = 1;
        }
    }

    ll get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(ll u, ll v, int timer)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(mp[u].size() < mp[v].size()) swap(u,v);
        par[v] = u;
        for(pii p : mp[v])
        {
            int x = p.fi, d = p.se;
            mp[u][x] += d;
            if(res[x] == INF && mp[u][x] == cnt[x])
            {
                res[x] = timer;
            }
        }
        //s[u] += s[v];
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

int main()
{
    init();
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
        cnt[color[i]]++;
    }
    for(int i = 1; i <= m; i++)
    {
        res[i] = INF;
        if(cnt[i] == 1) res[i] = 0;
    }
    dsu.init(n);
    for(int i = 1; i <= q; i++)
    {
        int u,v;
        cin >> u >> v;
        dsu.join(u,v,i);
    }
    for(int i = 1; i <= m; i++)
    {
        cout << (res[i] == INF ? -1 : res[i]) << '\n';
    }
}
