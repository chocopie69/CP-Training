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

const int SZ = 1e6+5, BSIZE = 400;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q, color[SZ], st[SZ], ed[SZ], tour[SZ], timer = 0;

struct Query
{
    int lo, hi, k, id;
    Query(int _lo = 0, int _hi = 0, int _k = 0, int _id = 0) : lo(_lo), hi(_hi), k(_k), id(_id) {}

    bool operator < (const Query& other) const
    {
        if(lo / BSIZE != other.lo / BSIZE) return lo / BSIZE < other.lo / BSIZE;
        return hi < other.hi;
    }
};

vector<Query> queries;

vector<int> adj[SZ];

void dfs(int u, int prev)
{
    ++timer;
    tour[timer] = u;
    st[u] = timer;
    for(int v : adj[u])
    {
        if(v != prev) dfs(v,u);
    }
    ed[u] = timer;
}

int res[SZ], freq[SZ], cnt[SZ], cntBlock[SZ];

int getBlock(int pos)
{
    return (pos - 1) / BSIZE + 1;
}

void add(int x)
{
    int c = color[tour[x]];
    cnt[freq[c]]--;
    cntBlock[ getBlock(freq[c]) ]--;
    freq[c]++;
    cnt[freq[c]]++;
    cntBlock[ getBlock(freq[c]) ]++;
    //cout << 'x';
}

void del(int x)
{
    int c = color[tour[x]];
    cnt[freq[c]]--;
    cntBlock[ getBlock(freq[c]) ]--;
    freq[c]--;
    cnt[freq[c]]++;
    cntBlock[ getBlock(freq[c]) ]++;
    //cout << 'x';
}

int getRes(int lo, int hi)
{
    int blockL = getBlock(lo), blockR = getBlock(hi), sum = 0;
    if(blockL == blockR)
    {
        for(int i = lo; i <= hi; i++) sum += cnt[i];
    } else
    {
        for(int i = blockL+1; i < blockR; i++)
        {
            sum += cntBlock[i];
        }
        for(int i = lo; i <= BSIZE*blockL; i++) sum += cnt[i];
        for(int i = BSIZE*(blockR-1) + 1; i <= hi; i++) sum += cnt[i];
    }
    return sum;
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i <= q; i++)
    {
        int u,k;
        cin >> u >> k;
        queries.push_back({st[u], ed[u], k, i });
    }
    sort(all(queries));
    int curlo = 1, curhi = 0;
    for(Query q : queries)
    {
        int lo = q.lo, hi = q.hi, k = q.k, id = q.id;
        while(curhi < hi) add(++curhi);
        while(curhi > hi) del(curhi--);
        while(curlo > lo) add(--curlo);
        while(curlo < lo) del(curlo++);
        res[id] = getRes(k,n);
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
