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

#define TASKNAME "INCOME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 3e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Edge
{
    int v, w;
    Edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

int n, a[SZ], cnt, k[SZ];
vector<Edge> adj[SZ];

void build(int id = 1, int lo = 1, int hi = n)
{
    if(lo == hi)
    {
        k[id] = lo;
        return;
    }
    k[id] = ++cnt;
    int mid = (lo + hi) / 2;
    build(2*id, lo, mid);
    build(2*id+1, mid+1, hi);
    adj[k[2*id]].pb({k[id],0});
    //cout << k[2*id] << " -> " << k[id] << '\n';
    adj[k[2*id+1]].pb({k[id],0});
    //cout << k[2*id+1] << " -> " << k[id] << '\n';
}

void addEdge(int u, int v, int p, int id = 1, int lo = 1, int hi = n)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        adj[k[id]].pb({p, 1});
        //cout << k[id] << " -> " << p << '\n';
        return;
    }
    int mid = (lo + hi) / 2;
    addEdge(u, v, p, 2*id, lo, mid);
    addEdge(u, v, p, 2*id+1, mid+1, hi);
}

vector<int> vec;

bool cmp(int x, int y)
{
    return a[x] < a[y];
}

int d[SZ], res = 0;
deque<int> dq;
bool vis[SZ];

void bfs()
{
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        for(Edge e : adj[u])
        {
            int v = e.v, w = e.w;
            if(vis[v] || d[v] <= d[u] + w) continue;
            vis[v] = true;
            d[v] = d[u] + w;
            if(w == 1) dq.pb(v);
            else dq.push_front(v);
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vec.pb(i);
    }
    cnt = n;
    build();
    for(int i = 1; i <= n; i++)
    {
        int lo, hi;
        cin >> lo >> hi;
        addEdge(lo, hi, i);
    }
    for(int i = 1; i < SZ; i++)
    {
        d[i] = INF;
    }
    sort(all(vec), cmp);
    int prev = a[vec[0]];
    while(!vec.empty())
    {
        int cur = a[vec.back()];
        while(!vec.empty() && a[vec.back()] == cur)
        {
            int x = vec.back();
            vec.pop_back();
            if(vis[x]) continue;
            vis[x] = true;
            dq.push_front(x);
            d[x] = 0;
        }
        bfs();
    }
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == INF) continue;
        res = max(res, d[i]);
    }
    cout << res + 1;
}
