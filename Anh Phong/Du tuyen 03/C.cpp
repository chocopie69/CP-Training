#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

#define TASKNAME "NAME"

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ], q, res[SZ];

struct Query
{
    int lo, hi, id;
    Query(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}

    bool operator < (const Query& other) const
    {
        return lo > other.lo;
    }
};

Query b[SZ];
stack<int> st;

struct SegTree
{
    struct Node
    {
        int mx1, mx2, lazy;
        Node(int _mx1 = 0, int _mx2 = 0, int _lazy = 0) : mx1(_mx1), mx2(_mx2), lazy(_lazy) {}

        Node operator + (const Node& other) const
        {
            return { max(mx1, other.mx1), max(mx2, other.mx2), 0 };
        }
    } nodes[4*SZ];

    void build(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = {a[lo],a[lo], 0};
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void down(int id, int lo, int hi)
    {
        int t = nodes[id].lazy;
        nodes[2*id].mx1 = max(nodes[2*id].mx1, nodes[2*id].mx2 + t);
        nodes[2*id].lazy = max(nodes[2*id].lazy, t);
        nodes[2*id+1].mx1 = max(nodes[2*id+1].mx1, nodes[2*id+1].mx2 + t);
        nodes[2*id+1].lazy = max(nodes[2*id+1].lazy, t);
        nodes[id].lazy = 0;
    }

    int u, v, val;

    void updateR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return;
        if(lo >= u && hi <= v)
        {
            nodes[id].mx1 = max(nodes[id].mx1, nodes[id].mx2 + val);
            nodes[id].lazy = max(nodes[id].lazy, val);
            return;
        }
        down(id, lo, hi);
        int mid = (lo + hi) / 2;
        updateR(2*id, lo, mid);
        updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int u, int v, int val)
    {
        if(u > v) return;
        SegTree::u = u;
        SegTree::v = v;
        SegTree::val = val;
        updateR(1, 1, n);
    }

    Node queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return {0,0,0};
        if(lo >= u && hi <= v) return nodes[id];
        down(id, lo, hi);
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    Node query(int u, int v)
    {
        if(u > v) return {0,0,0};
        SegTree::u = u;
        SegTree::v = v;
        return queryR(1, 1, n);
    }
} seg;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int lo,hi;
        cin >> lo >> hi;
        b[i] = {lo,hi,i};
    }
    sort(b + 1, b + q + 1);
    int j = n;
    seg.build(1, 1, n);
    for(int i = 1; i <= q; i++)
    {
        int lo = b[i].lo, hi = b[i].hi, id = b[i].id;
        //cout << lo << " - " << hi << '\n';
        while(j >= lo)
        {
            while(!st.empty())
            {
                int x = st.top();
                seg.update(x + x - j, n, a[j] + a[x]);
                if(a[x] >= a[j]) break;
                st.pop();
            }
            st.push(j);
            j--;
        }
        res[id] = seg.query(lo, hi).mx1;
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}

