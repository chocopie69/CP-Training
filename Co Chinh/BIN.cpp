#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "BIN"

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

int q, x, y, t, s[SZ];

struct DSU
{
    int par[SZ];

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
        }
    }

    int get(int u)
    {
        return par[u] == u ? u : par[u] = get(par[u]);
    }

    void join(int u, int v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(s[u] < s[v]) swap(u,v);
        par[v] = u;
        s[v] += s[u];
    }

    bool joined(int u, int v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

int main()
{
    init();
    cin >> q;
    dsu.init(1e5+5);
    while(q--)
    {
        cin >> x >> y >> t;
        if(t == 1)
        {
            dsu.join(x,y);
        } else
        {
            cout << (dsu.joined(x,y)) << '\n';
        }
    }
}

