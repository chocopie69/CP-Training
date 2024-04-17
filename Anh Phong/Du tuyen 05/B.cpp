#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Query
{
    int lo, hi, id;
    Query(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}
};

int n, m, q;
vector<pll> a[SZ];
vector<Query> b[SZ];
ll res[SZ];

struct SegTree
{
    struct Node
    {
        ll mx, sum, pre, suf;
        Node(ll _mx = 0, ll _sum = 0, ll _pre = 0, ll _suf = 0) : mx(_mx), sum(_sum), pre(_pre), suf(_suf) {}

        Node operator + (const Node& other) const
        {
            return { max({ mx, other.mx, suf + other.pre }), sum + other.sum, max(pre, sum + other.pre), max(other.suf, suf + other.sum) };
        }
    } nodes[4*SZ];

    int pos;
    ll val;

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id].mx += val;
            nodes[id].sum += val;
            nodes[id].pre += val;
            nodes[id].suf += val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) updateR(2*id, lo, mid);
        else updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int pos, ll val)
    {
        SegTree::pos = pos;
        SegTree::val = val;
        updateR(1, 1, m);
    }

    int u,v;

    Node queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return {-INFLL, 0, -INFLL, -INFLL};
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    Node query(int u, int v)
    {
        SegTree::u = u;
        SegTree::v = v;
        return queryR(1, 1, m);
    }
} seg;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int lo, hi;
        ll x;
        cin >> lo >> hi >> x;
        a[lo].push_back({i, x});
        a[hi+1].push_back({i, -x});
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int k, lo, hi;
        cin >> k >> lo >> hi;
        b[k].push_back({lo, hi, i});
    }
    for(int i = 1; i <= n; i++)
    {
        for(pll p : a[i])
        {
            int pos = p.fi;
            ll val = p.se;
            seg.update(pos, val);
        }
        for(Query p : b[i])
        {
            int lo = p.lo, hi = p.hi, id = p.id;
            res[id] = seg.query(lo, hi).mx;
        }
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}

