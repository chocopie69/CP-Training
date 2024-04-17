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

const int SZ = 1e5+5, BSIZE = 320;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,q,c[SZ], timer = 0, tour[SZ], st[SZ], ed[SZ];

vector<int> adj[SZ];

void dfs(int u, int p)
{
    ++timer;
    tour[timer] = u;
    st[u] = timer;
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs(v,u);
    }
    ed[u] = timer;
}

struct Query
{
    int lo, hi, k, id;
    Query(int _lo = 0, int _hi = 0, int _k = 0, int _id = 0)
    {
        lo = _lo;
        hi = _hi;
        k = _k;
        id = _id;
    }
};

Query queries[SZ];

bool cmp(Query x, Query y)
{
    if(x.lo / BSIZE != y.lo / BSIZE) return x.lo / BSIZE < y.lo / BSIZE;
    return x.hi < y.hi;
}

int freq[SZ], cnt[SZ], cnt2[SZ], res[SZ];

void add(ll x)
{
    cnt[freq[x] / BSIZE ]--;
    cnt2[freq[x]]--;
    freq[x]++;
    cnt[freq[x] / BSIZE ]++;
    cnt2[freq[x]]++;
}

void del(ll x)
{
    cnt[freq[x] / BSIZE ]--;
    cnt2[freq[x]]--;
    freq[x]--;
    cnt[freq[x] / BSIZE ]++;
    cnt2[freq[x]]++;
}

int getRes(int lo, int hi)
{
    int blockLo = lo / BSIZE, blockHi = hi / BSIZE, sum = 0;
    if(blockLo == blockHi)
    {
        for(int i = lo; i <= hi; i++)
        {
            sum += cnt2[i];
        }
        return sum;
    }
    for(int i = blockLo + 1; i <= blockHi - 1; i++)
    {
        sum += cnt[i];
    }
    for(int i = lo; i <= (blockLo + 1)*BSIZE - 1; i++)
    {
        sum += cnt2[i];
    }
    for(int i = blockHi*BSIZE; i <= hi; i++)
    {
        sum += cnt2[i];
    }
    return sum;
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= q; i++)
    {
        int u,k;
        cin >> u >> k;
        queries[i] = {st[u], ed[u], k, i};
    }
    sort(queries + 1, queries + q + 1, cmp);
    int curlo = 1, curhi = 0;
    for(int i = 1; i <= q; i++)
    {
        int lo = queries[i].lo, hi = queries[i].hi, k = queries[i].k, id = queries[i].id;
        while(curlo > lo) add(c[tour[--curlo]]);
        while(curhi < hi) add(c[tour[++curhi]]);
        while(curlo < lo) del(c[tour[curlo++]]);
        while(curhi > hi) del(c[tour[curhi--]]);
        res[id] = getRes(k, n);
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
