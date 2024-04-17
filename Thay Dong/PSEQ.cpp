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

int n,q, a[SZ], b[SZ], pos[SZ], d[SZ];

int dist(int i, int j)
{
    return (i <= j ? j-i : n-i+j);
}

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
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    void update(int pos, ll val)
    {
        SegmentTree::pos = pos;
        SegmentTree::val = val;
        updateR(1, 0, n-1);
    }
} seg;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        d[b[i]] = dist(pos[b[i]],i);
        seg.update(d[b[i]],1);
    }
    while(q--)
    {
        int i,j;
        cin >> i >> j;
        seg.update(d[b[i]],-1);
        d[b[i]] = dist(pos[b[i]], j);
        seg.update(d[b[i]],1);

        seg.update(d[b[j]],-1);
        d[b[j]] = dist(pos[b[j]], i);
        seg.update(d[b[j]], 1);
        swap(b[i],b[j]);
        cout << seg.nodes[1] << '\n';
    }
}
