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

int n,q,a[SZ],cnt[SZ], res[SZ], cur = 0;

Query queries[SZ];

bool cmp(Query x, Query y)
{
    if(x.lo / BSIZE != y.lo / BSIZE)
    {
        return x.lo / BSIZE < y.lo / BSIZE;
    }
    return x.hi < y.hi;
}

void add(ll x)
{
    if(x > n) return;
    if(cnt[x] == x) cur--;
    cnt[x]++;
    if(cnt[x] == x) cur++;
}

void del(ll x)
{
    if(x > n) return;
    if(cnt[x] == x) cur--;
    cnt[x]--;
    if(cnt[x] == x) cur++;
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> queries[i].lo >> queries[i].hi;
        queries[i].id = i;
    }
    sort(queries + 1, queries + q + 1, cmp);
    int curlo = queries[1].lo, curhi = queries[1].hi;
    for(int i = curlo; i <= curhi; i++)
    {
        add(a[i]);
    }
    res[queries[1].id] = cur;
    for(int i = 2; i <= q; i++)
    {
        while(curlo < queries[i].lo)
        {
            del(a[curlo]);
            curlo++;
        }
        while(curlo > queries[i].lo)
        {
            curlo--;
            add(a[curlo]);
        }
        while(curhi > queries[i].hi)
        {
            del(a[curhi]);
            curhi--;
        }
        while(curhi < queries[i].hi)
        {
            curhi++;
            add(a[curhi]);
        }
        res[queries[i].id] = cur;
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
