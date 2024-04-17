#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TOURISTS"

using namespace std;

const int SZ = 1e6+5, BSIZE = 500;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, a[SZ], q, cnt[SZ], cur = 0, res[SZ];

struct Query
{
    int lo,hi,id;
    Query(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}

    bool operator < (const Query& other) const
    {
        if(lo / BSIZE != other.lo / BSIZE)
        {
            return lo / BSIZE < other.lo / BSIZE;
        }
        return hi < other.hi;
    }
};

Query queries[SZ];
vector<int> nen;

void add(int x)
{
    int c = a[x];
    if(cnt[c] == 0) cur++;
    cnt[c]++;
}

void del(int x)
{
    int c = a[x];
    cnt[c]--;
    if(cnt[c] == 0) cur--;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    for(int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(nen),a[i]) - nen.begin() + 1;
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int lo,hi;
        cin >> lo >> hi;
        queries[i] = {lo, hi, i};
    }
    sort(queries + 1, queries + q + 1);
    int curlo = 1, curhi = 0;
    for(int i = 1; i <= q; i++)
    {
        int lo = queries[i].lo, hi = queries[i].hi, id = queries[i].id;
        while(curhi < hi) add(++curhi);
        while(curhi > hi) del(curhi--);
        while(curlo < lo) del(curlo++);
        while(curlo > lo) add(--curlo);
        res[id] = cur;
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
