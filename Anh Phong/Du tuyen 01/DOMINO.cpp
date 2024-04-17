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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Domino
{
    int x, h, id;
    Domino(int _x = 0, int _h = 0, int _id = 0) : x(_x), h(_h), id(_id) {}

    bool operator < (const Domino& other) const
    {
        return x < other.x;
    }
};

int n, res[SZ];
Domino a[SZ];

struct SegmentTree
{
    int nodes[4*SZ];

    int pos, val;

    void buildR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = lo;
            return;
        }
        int mid = (lo + hi) / 2;
        buildR(2*id, lo, mid);
        buildR(2*id+1, mid+1, hi);
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = max(nodes[id],val);
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid)
        {
            updateR(2*id, lo, mid);
        } else
        {
            updateR(2*id+1, mid+1, hi);
        }
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    void update(int pos, int val)
    {
        SegmentTree::pos = pos;
        SegmentTree::val = val;
        updateR(1, 1, n);
    }

    int u,v;

    int queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return max(queryR(2*id, lo, mid), queryR(2*id+1, mid+1, hi));
    }

    int query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} seg;

int bs(int pos)
{
    int lo = pos, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(a[pos].x + a[pos].h - 1 >= a[mid].x)
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    return hi;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].h;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    seg.buildR(1, 1, n);
    for(int i = n; i >= 1; i--)
    {
        int x = a[i].x, h = a[i].h, id = a[i].id, pos = bs(i);
        //cout << a[i].x << " " << pos << '\n';
        res[id] = seg.query(i, pos) - i + 1;
        //cout << seg.query(i, pos) << '\n';
        seg.update(i, seg.query(i, pos));
    }
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}
