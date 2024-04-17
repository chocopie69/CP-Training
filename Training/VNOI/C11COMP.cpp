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

int n,m,k,q,c[SZ], timer = 0, tour[SZ], st[SZ], ed[SZ];

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
    int lo, hi, id;
    Query(int _lo = 0, int _hi = 0, int _id = 0)
    {
        lo = _lo;
        hi = _hi;
        id = _id;
    }
};

Query queries[SZ];

bool cmp(Query x, Query y)
{
    if(x.lo / BSIZE != y.lo / BSIZE) return x.lo / BSIZE < y.lo / BSIZE;
    return x.hi < y.hi;
}

int cnt[SZ], cnt2[SZ], res[SZ], cur;

void add(ll x)
{
    if(cnt[x] == 0) cur++;
    cnt[x]++;
    cnt2[cnt[x]]++;
}

void del(ll x)
{
    cnt2[cnt[x]]--;
    cnt[x]--;
    if(cnt[x] == 0) cur--;
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int u;
        cin >> u;
        queries[i] = {st[u], ed[u], i};
    }
    sort(queries + 1, queries + q + 1, cmp);
    int curlo = 1, curhi = 0;
    for(int i = 1; i <= q; i++)
    {
        int lo = queries[i].lo, hi = queries[i].hi, id = queries[i].id;
        while(curlo > lo) add(c[tour[--curlo]]);
        while(curhi < hi) add(c[tour[++curhi]]);
        while(curlo < lo) del(c[tour[curlo++]]);
        while(curhi > hi) del(c[tour[curhi--]]);
        res[id] = cur - cnt2[k+1];
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}

