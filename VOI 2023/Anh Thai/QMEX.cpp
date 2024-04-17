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

const int SZ = 1e6+5, BSIZE = 600;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Query
{
    int lo, hi, id;
    Query(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}

    bool operator < (const Query& other) const
    {
        return hi < other.hi;
    }
};
int n,q, a[SZ], res[SZ];
Query b[SZ];

struct SegTree
{
    int nodes[4*SZ];

    int pos, val;

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid)
            updateR(2*id, lo, mid);
        else
            updateR(2*id+1, mid+1, hi);
        nodes[id] = min(nodes[2*id], nodes[2*id+1]);
    }

    void update(int pos, int val)
    {
        SegTree::pos = pos;
        SegTree::val = val;
        updateR(1, 0, n);
    }

    int qlo;

    int queryR(int id, int lo, int hi)
    {
        if(lo == hi) return lo;
        int mid = (lo + hi) / 2;
        if(nodes[2*id] < qlo) return queryR(2*id, lo, mid);
        return queryR(2*id+1, mid+1, hi);
    }

    int query(int qlo)
    {
        SegTree::qlo = qlo;
        return queryR(1, 0, n);
    }
} seg;

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
        cin >> b[i].lo >> b[i].hi;
        b[i].id = i;
    }
    sort(b + 1, b + q + 1);
    int j = 1;
    for(int i = 1; i <= q; i++)
    {
        int lo = b[i].lo, hi = b[i].hi, id = b[i].id;
        while(j <= hi)
        {
            seg.update(a[j], j);
            j++;
        }
        res[id] = seg.query(lo);
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
