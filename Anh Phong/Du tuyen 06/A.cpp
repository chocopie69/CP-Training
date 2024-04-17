#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5, BS = 800;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct DSU
{
    int lab[SZ];
    vector<pii> save;

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            lab[i] = -1;
        }
    }

    int get(ll u)
    {
        return (lab[u] < 0 ? u : get(lab[u]));
    }

    void join(int u, int v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(lab[u] > lab[v]) swap(u,v);
        save.pb({v, lab[v]});
        lab[u] += lab[v];
        lab[v] = u;
    }

    void undo()
    {
        pii p = save.back();
        int v = p.fi, u = lab[v];
        lab[v] = p.se;
        lab[u] -= lab[v];
        save.pop_back();
    }

    void rollback(int _n)
    {
        while(save.size() > _n) undo();
    }

} dsu;

struct Edge
{
    int u, v, w, id;
};
Edge e[SZ];

struct Query
{
    int t, x, y;
};
Query b[SZ];

int n, m, q, res[SZ];
bool changed[SZ];
vector<int> block, join[SZ];

bool cmp1(int i, int j)
{
    return b[i].y > b[j].y;
}

bool cmp2(int i, int j)
{
    return e[i].w > e[j].w;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    cin >> q;
    block.pb(0);
    int cnt = 0;
    for(int i = 1; i <= q; i++)
    {
        cin >> b[i].t >> b[i].x >> b[i].y;
        ++cnt;
        if(cnt >= BS)
        {
            cnt = 0;
            block.pb(i);
        }
    }
    block.pb(q);
    for(int k = 0; k < block.size() - 1; k++)
    {
        int lo = block[k] + 1, hi = block[k + 1];
        dsu.init(n);
        vector<int> ask, unstable, unchanged;
        for(int i = lo; i <= hi; i++)
        {
            if(b[i].t == 2)
            {
                ask.pb(i);
            } else
            {
                changed[b[i].x] = true;
                unstable.pb(i);
            }
        }
        for(int i = 1; i <= m; i++)
        {
            if(!changed[i]) unchanged.pb(i);
            changed[i] = false;
        }
        for(int i = lo; i <= hi; i++)
        {
            if(b[i].t == 1)
            {
                e[b[i].x].w = b[i].y;
            } else
            {
                join[i-lo].clear();
                for(int j : unstable)
                {
                    if(e[b[j].x].w >= b[i].y) join[i-lo].pb(b[j].x);
                }
            }
        }
        sort(all(ask), cmp1);
        sort(all(unchanged), cmp2);
        int j = 0;
        for(int i = 0; i < ask.size(); i++)
        {
            int id = ask[i];
            while(j < unchanged.size() && e[unchanged[j]].w >= b[id].y )
            {
                int u = e[unchanged[j]].u, v = e[unchanged[j]].v;
                dsu.join(u,v);
                ++j;
            }
            int prevS = dsu.save.size();
            for(int jj : join[id-lo])
            {
                int u = e[jj].u, v = e[jj].v;
                dsu.join(u,v);
            }
            res[id] = - dsu.lab[ dsu.get(b[id].x) ];
            dsu.rollback(prevS);
        }
    }
    for(int i = 1; i <= q; i++)
    {
        if(b[i].t == 2) cout << res[i] << '\n';
    }
}

