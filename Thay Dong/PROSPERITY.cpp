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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q, tour[SZ], st[SZ], ed[SZ], pos[SZ], timer = 0, par[SZ];
vector<int> adj[SZ];
ll a[SZ];
bool vis[SZ], leaf[SZ];
queue<int> qu;

void bfs(int s)
{
    qu.push(s);
    vis[s] = true;
    timer = 1;
    tour[timer] = s;
    pos[s] = timer;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        bool flag = false;
        for(int v : adj[u])
        {
            if(vis[v]) continue;
            vis[v] = true;
            par[v] = u;
            flag = true;
            timer++;
            st[u] = min(st[u], timer);
            ed[u] = max(ed[u], timer);
            tour[timer] = v;
            pos[v] = timer;
            qu.push(v);
        }
        if(!flag) leaf[u] = true;
    }
}

struct SegmentTree
{
    ll nodes[4*SZ], lazy[4*SZ];

    int u,v;
    ll val;

    void buildR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = a[tour[lo]];
            return;
        }
        int mid = (lo + hi) / 2;
        buildR(2*id, lo, mid);
        buildR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void down(int id, int lo, int hi)
    {
        ll t = lazy[id];
        lazy[id] = 0;
        if(lo == hi) return;
        int mid = (lo + hi) / 2, len1 = mid-lo+1, len2 = hi-mid;
        nodes[2*id] += t*len1;
        lazy[2*id] += t;
        nodes[2*id+1] += t*len2;
        lazy[2*id+1] += t;
    }

    void updateR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return;
        if(lo >= u && hi <= v)
        {
            nodes[id] += val*(hi - lo + 1);
            lazy[id] += val;
            return;
        }
        down(id, lo, hi);
        int mid = (lo + hi) / 2;
        updateR(2*id, lo, mid);
        updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int u, int v, ll val)
    {
        if(u > v) return;
        SegmentTree::u = u;
        SegmentTree::v = v;
        SegmentTree::val = val;
        updateR(1, 1, n);
    }

    ll queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v) return nodes[id];
        down(id, lo, hi);
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    ll query(int u, int v)
    {
        if(u > v) return 0;
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} seg;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i] = INF;
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
//    for(int i = 1; i <= n; i++)
//    {
//        cout << tour[i] << " " << st[tour[i]] << " " << ed[tour[i]] << '\n';
//    }
    seg.buildR(1,1,n);
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int i;
            ll x;
            cin >> i >> x;
            if(!leaf[i]) seg.update(st[i],ed[i],x);
            seg.update(pos[i], pos[i], x*2);
            if(i != 1) seg.update(pos[par[i]], pos[par[i]], x);
            //cout << i << " " << st[i] << ' ' << ed[i] << " " << pos[i] << '\n';
        } else
        {
            int i;
            cin >> i;
            ll res = 0;
            if(!leaf[i]) res += seg.query(st[i],ed[i]);
            res += seg.query(pos[i], pos[i]);
            if(i != 1) res += seg.query(pos[par[i]], pos[par[i]]);
            cout << res << '\n';
            //cout << "query " << i << " " << st[i] << ' ' << ed[i] << '\n';
        }
    }
//    for(int i = 1; i <= n; i++)
//    {
//        cout << i << " " << seg.query(i,i) << '\n';
//    }
}

/*
5 4
0 0 0 0 0
1 2
1 3
2 4
3 5
1 1 4
1 3 2
2 2
2 3
*/

