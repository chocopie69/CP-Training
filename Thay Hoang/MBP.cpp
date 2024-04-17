#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MBP"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    int v,w;
    Edge(int _v = 0, int _w = 0)
    {
        v = _v;
        w = _w;
    }
};

int t,n,q,hldList[SZ],s[SZ], head[SZ], cnt = 0, pos[SZ], parent[SZ], d[SZ], seg[4*SZ];
vector<Edge> adj[SZ];
vector<int> children[SZ];
pii edges[SZ];

void dfs(int u, int prev)
{
    s[u] = 1;
    for(Edge e : adj[u])
    {
        int v = e.v, w = e.w;
        if(v == prev) continue;
        dfs(v,u);
        s[u] += s[v];
        parent[v] = u;
        children[u].push_back(v);
        d[v] = w;
    }
}

void hld(int u, int h)
{
    head[u] = h;
    cnt++;
    hldList[cnt] = u;
    pos[u] = cnt;
    if(children[u].empty()) return;
    int nextV, maxS = -INF;
    for(int v : children[u])
    {
        if(s[v] > maxS)
        {
            maxS = s[v];
            nextV = v;
        }
    }
    hld(nextV,h);
    for(int v : children[u])
    {
        if(v != nextV)
        {
            hld(v,v);
        }
    }
}

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = d[hldList[lo]];
        //cout << "mmb " << seg[id] << " " << id << '\n';
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = min(seg[2*id],seg[2*id+1]);
}

void update(int id, int lo, int hi, int pos, int val)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id] = val;
        //cout << "mmb " << seg[id] << " " << id << '\n';
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos,val);
    update(2*id+1,mid+1,hi,pos,val);
    seg[id] = min(seg[2*id],seg[2*id+1]);
}

int query(int id, int lo, int hi, int u, int v)
{
    if(lo > hi || lo > v || hi < u) return INF;
    if(lo >= u && hi <= v)
    {
        //cout << seg[id] << " " << id << '\n';
        return seg[id];
    }
    int mid = (lo + hi) / 2;
    return min(query(2*id,lo,mid,u,v),query(2*id+1,mid+1,hi,u,v));
}

int getAns(int u, int v)
{
    int res = INF;
    while(head[u] != head[v])
    {
        if(s[head[u]] < s[head[v]])
        {
            int cur = query(1,1,n,pos[head[u]],pos[u]);
            res = min(res,cur);
            //cout << u << " " << pos[head[u]] << " " << pos[u] << " " << cur << '\n';
            u = parent[head[u]];
        } else
        {
            int cur = query(1,1,n,pos[head[v]],pos[v]);
            res = min(res,cur);
            //cout << v << " " << pos[head[v]] << " " << pos[v] << " " << cur << '\n';
            v = parent[head[v]];
        }
    }
    if(u == v) return res;
    if(s[u] < s[v]) swap(u,v);
    return min(res,query(1,1,n,pos[u]+1,pos[v]));

}

void reset()
{
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        children[i].clear();
        head[i] = 0;
        pos[i] = 0;
        d[i] = 0;
        hldList[i] = 0;
        s[i] = 0;
        parent[i] = 0;
    }
    d[1] = 0;
    cnt = 0;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        reset();
        for(int i = 1; i < n; i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            edges[i] = {u,v};
        }
        dfs(1,0);
        hld(1,1);
//        for(int i = 1; i <= cnt; i++)
//        {
//            cout << hldList[i] << " " << head[hldList[i]] << '\n';
//        }
//        cout << '\n';
        build(1,1,n);
        while(q--)
        {
            char c;
            cin >> c;
            if(c == 'Q')
            {
                int u,v;
                cin >> u >> v;
                cout << getAns(u,v) << '\n';
            } else
            {
                int i,k;
                cin >> i >> k;
                int u = edges[i].fi, v = edges[i].se;
                if(parent[u] == v) swap(u,v);
                d[v] = k;
                update(1,1,n,pos[v],k);
            }
        }
    }
}

/*
1
8 2
1 2 1
2 3 2
1 5 3
4 5 4
5 7 5
6 7 6
7 8 7
Q 2 5
Q 6 4
*/
