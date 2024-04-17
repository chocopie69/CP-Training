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

const int SZ = 1e5+5, BSIZE = 1e2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, d[SZ], timer = 0, pos[SZ], st[SZ], ed[SZ], tour[SZ];
ll sum[SZ], val[SZ], x[SZ];
vector<int> adj[SZ], vertices[SZ];
vector<pair<int,ll>> q;

void preDfs(int u)
{
    tour[++timer] = u;
    pos[u] = timer;
    st[u] = timer;
    for(int v : adj[u])
    {
        d[v] = d[u] + 1;
        preDfs(v);
    }
    ed[u] = timer;
}

void dfs(int u)
{
    sum[u] = val[u];
    for(int v : adj[u])
    {
        dfs(v);
        sum[u] += sum[v];
    }
}

void buildTree()
{
    for(pair<int,ll> p : q)
    {
        x[p.fi] += p.se;
    }
    q.clear();
    for(int u = 1; u <= n; u++)
    {
        val[u] += x[d[u]];
    }
    memset(x, 0, sizeof(x));
    dfs(1);
}

int bs(int l, int pos)
{
    return lower_bound(all(vertices[l]), pos) - vertices[l].begin();
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    preDfs(1);
    for(int u = 1; u <= n; u++)
    {
        vertices[d[u]].push_back(pos[u]);
    }
    for(int i = 0; i < n; i++)
    {
        sort(all(vertices[i]));
//        cout << i << ": ";
//        for(int k : vertices[i]) cout << k << ' ';
//        cout << '\n';
    }
//    for(int i = 1; i <= n; i++)
//    {
//        cout << tour[i] << " ";
//    }
    for(int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l;
            ll x;
            cin >> l >> x;
            q.push_back({l,x});
            if(q.size() >= BSIZE) buildTree();
        } else
        {
            int u;
            cin >> u;
            ll res = sum[u];
            int lo = st[u], hi = ed[u];
            //cout << lo << " " << hi << '\n';
            for(pair<int,ll> p : q)
            {
                int l = p.fi;
                ll x = p.se;
                int pos1 = bs(l,lo), pos2 = upper_bound(all(vertices[l]), hi) - vertices[l].begin() - 1;
                //cout << pos1 << " - " << pos2 << " - " << l << " " << x << '\n';
                if(pos1 > pos2) continue;
                res += (pos2-pos1+1)*x;
            }
            cout << res << '\n';
        }
    }
}

/*
5 3
1 2
1 3
3 4
3 5
1 1 2
1 2 3
2 3
*/

