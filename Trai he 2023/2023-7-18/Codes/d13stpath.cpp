// vegnim
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define sz(x) (int)x.size()
#define task ""

const ll INF = 1e18;
const int maxN = 1e5+5;

int n,m,q,par[maxN][20],h[maxN];
pair <pii,int> edge[maxN];
vector <pii> adj[maxN],st[maxN];
vector <pair <pii,int> > out;
ll disRoot[maxN],dis[25][maxN];

struct DSU
{
    int lab[maxN];

    DSU() { memset(lab, -1, sizeof lab); }

    int findSet(const int& u)
    {
        if (lab[u] < 0) return u;
        return lab[u] = findSet(lab[u]);
    }

    void joinSet(int u, int v)
    {
        int a = findSet(u), b = findSet(v);
        if (a == b) return;
        if (lab[a] > lab[b]) swap(a,b);
        lab[a] += lab[b];
        lab[b] = a;
    }
};

DSU s;

void getST()
{
    for (int i=1; i<=m; i++){
        int u = edge[i].fi.fi, v = edge[i].fi.se, w = edge[i].se;
        if (s.findSet(u) == s.findSet(v)){
            out.pb(edge[i]);
            continue;
        }
        s.joinSet(u, v);
        st[u].pb({v, w});
        st[v].pb({u, w});
    }
}

void dfs(int u, int prev)
{
    h[u] = h[prev] + 1;
    par[u][0] = (u == prev) ? 0 : prev;
    for (int i=1; i<=16; i++){
        par[u][i] = par[par[u][i-1]][i-1];
    }
    for (auto p : st[u]){
        int v = p.fi, w = p.se;
        if (v == prev) continue;
        disRoot[v] = disRoot[u] + w;
        dfs(v, u);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u,v);
    for (int step = h[u]-h[v], bit=16; bit >= 0; bit--){
        if ((step >> bit) & 1){
            u = par[u][bit];
        }
    }
    if (u == v) return u;
    for (int i=16; i>=0; i--){
        if (par[u][i] == par[v][i]) continue;
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

priority_queue <pll, vector<pll>, greater<pll> > pq;

void dijkstra(int i)
{
    pq.push({0, out[i].fi.fi});
    dis[i][out[i].fi.fi] = 0;
    while (!pq.empty()){
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (dis[i][u] < d) continue;
        for (auto p : adj[u]){
            int v = p.fi, w = p.se;
            if (dis[i][v] > d + w){
                dis[i][v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr);
//    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    freopen("inp.txt","r",stdin);
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        edge[i] = {{u,v},w};
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    getST();
    dfs(1, 1);
    for (int i=0; i<21; i++){
        for (int j=1; j<=n; j++){
            dis[i][j] = INF;
        }
    }
    for (int i=0; i<sz(out); i++){
        dijkstra(i);
    }
    while (q--){
        int u,v; cin >> u >> v;
        ll ans = INF;
        int anc = LCA(u,v);
        ans = min(ans, disRoot[u] + disRoot[v] - disRoot[anc]*2);
        for (int i=0; i<sz(out); i++){
            ans = min(ans, dis[i][u] + dis[i][v]);
        }
        cout << ans<<'\n';
    }
    return 0;
}
