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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q;

struct SegmentTree
{
    int pos;
    ll val;

    ll nodes[4*SZ];

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] += val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) updateR(2*id, lo, mid);
        else updateR(2*id+1, mid+1, hi);
        nodes[id] = min(nodes[2*id], nodes[2*id+1]);
    }

    void update(int pos, ll val)
    {
        SegmentTree::pos = pos;
        SegmentTree::val = val;
        updateR(1, 1, n);
    }

    int u, v;

    ll queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return INFLL;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return min(queryR(2*id, lo, mid), queryR(2*id+1, mid+1, hi));
    }

    ll query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} seg;

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int pos;
            ll val;
            cin >> pos >> val;
            seg.update(pos,val);
        } else
        {
            int u,v;
            cin >> u >> v;
            if(u <= v)
                cout << seg.query(u,v) << '\n';
            else
                cout << min(seg.query(u,n), seg.query(1,v)) << '\n';
        }
    }
}
