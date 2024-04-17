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
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 4e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Query
{
    int lo, hi, id, t;
    ll lim, k;
    Query(int _lo = 0, int _hi = 0, int _id = 0, int _t = 0, ll _lim = 0, ll _k = 0) : lo(_lo), hi(_hi), id(_id), t(_t), lim(_lim), k(_k) {}

    bool operator < (const Query& other) const
    {
        return lim < other.lim;
    }
};

struct SegTree
{
    ll nodes[4*SZ];

    void build(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = 1;
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = (nodes[2*id] * nodes[2*id+1]) % MOD;
    }

    void update(int id, int lo, int hi, int pos, ll val)
    {
        if(lo == hi)
        {
            nodes[id] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) update(2*id, lo, mid, pos, val);
        else update(2*id+1, mid+1, hi, pos , val);
        nodes[id] = (nodes[2*id] * nodes[2*id+1]) % MOD;
    }

    ll query(int id, int lo, int hi, int u, int v)
    {
        if(lo > v || hi < u) return 1LL;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return (query(2*id, lo, mid, u, v) * query(2*id+1, mid+1, hi, u, v)) % MOD;
    }
} seg;

ll n,q,a[SZ], res[2][SZ];
pll b[SZ];
vector<Query> qr;

ll power(ll x, ll y)
{
    if(y == 0) return 1LL;
    ll cur = power(x, y/2);
    if(y % 2 == 0) return (cur * cur) % MOD;
    else return ((cur * cur) % MOD * (x % MOD)) % MOD;
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = {a[i],i};
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= q; i++)
    {
        ll lo,hi,x,y,k;
        cin >> lo >> hi >> x >> y >> k;
        qr.pb({lo, hi, i, 0, x-1, k});
        qr.pb({lo, hi, i, 1, y, k});
    }
    sort(all(qr));
    int j = 1;
    seg.build(1, 1, n);
    for(Query cur : qr)
    {
        int lo = cur.lo, hi = cur.hi, id = cur.id, t = cur.t;
        ll lim = cur.lim, k = cur.k;
        while(j <= n && b[j].fi <= lim)
        {
            seg.update(1, 1, n, b[j].se, b[j].fi);
            j++;
        }
        res[t][id] = power(seg.query(1, 1, n, lo, hi),k);
    }
    for(int i = 1; i <= q; i++)
    {
        cout << (res[1][i] * power(res[0][i],MOD-2)) % MOD << '\n';
    }
}

