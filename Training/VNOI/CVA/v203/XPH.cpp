#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "XPH"

using namespace std;

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;
vector<int> nen;

int getPos(int x)
{
    return lower_bound(all(nen),x) - nen.begin() + 1;
}

struct SegmentTree
{
    int nodes[8*SZ];

    void reset()
    {
        memset(nodes,0,sizeof(nodes));
    }

    int pos;
    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id]++;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid)
            updateR(2*id, lo, mid);
        else
            updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int pos)
    {
        SegmentTree::pos = pos;
        updateR(1, 1, 2*n);
    }

    int u,v;
    int queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    int query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, 2*n);
    }
} seg;

struct Segment
{
    int lo, hi, id;
    Segment(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}

    bool operator < (const Segment& other) const
    {
        if(lo != other.lo)
            return lo < other.lo;
        return hi < other.hi;
    }
};

Segment a[SZ];
int res[SZ], res2[SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].lo >> a[i].hi;
        a[i].id = i;
        nen.push_back(a[i].lo);
        nen.push_back(a[i].hi);
    }
    sort(all(nen));
    for(int i = 1; i <= n; i++)
    {
        a[i].lo = getPos(a[i].lo);
        a[i].hi = getPos(a[i].hi);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        int lo = a[i].lo, hi = a[i].hi, id = a[i].id;
        res[id] += seg.query(a[i].lo, 2*n);
        seg.update(a[i].hi);
    }
    seg.reset();
    for(int i = n; i >= 1; i--)
    {
        int lo = a[i].lo, hi = a[i].hi, id = a[i].id;
        res2[id] += seg.query(1, a[i].hi);
        seg.update(a[i].lo);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] + res2[i] << '\n';
    }
}

/*
5 7
1 2
2 5
3 5
7 7
4 6
*/
