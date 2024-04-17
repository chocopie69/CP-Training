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

const int SZ = 2e5+2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, q, f[SZ];
ll a[SZ];

void preCompute()
{
    for(int i = 1; i < SZ; i++)
    {
        int pos = i;
        while(pos % 2 == 0)
        {
            pos /= 2;
        }
        f[i] = pos;
    }
}

struct SegmentTree
{
    ll nodes[4*SZ];

    void buildR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = a[lo] + a[f[lo]];
            return;
        }
        int mid = (lo + hi) / 2;
        buildR(2*id, lo, mid);
        buildR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void build()
    {
        buildR(1, 1, n);
    }

    int pos;

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = a[lo] + a[f[lo]];
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid)
        {
            updateR(2*id, lo, mid);
        } else updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int pos)
    {
        SegmentTree::pos = pos;
        updateR(1, 1, n);
    }

    int u,v;

    ll queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return 0LL;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    ll query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} st;

int main()
{
    init();
    cin >> n >> q;
    preCompute();
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    st.build();
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int pos;
            ll val;
            cin >> pos >> val;
            a[pos] = val;
            while(pos <= n)
            {
                st.update(pos);
                pos *= 2;
            }
        } else
        {
            int u,v;
            cin >> u >> v;
            cout << st.query(u,v) << '\n';
        }
    }
}
