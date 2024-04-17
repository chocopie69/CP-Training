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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+9, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string s;
int t, n;
ll a[SZ], pow2[SZ];

ll power(ll x, ll k)
{
    if(k == 0) return 1LL;
    ll cur = power(x, k / 2);
    cur = (cur * cur) % MOD;
    if(k % 2 == 1) cur = (cur * x) % MOD;
    return cur;
}

ll divide(ll x, ll y)
{
    return (x % MOD * power(y, MOD-2)) % MOD;
}

struct SegTree
{
    struct Node
    {
        ll val, s;
        Node(ll _val = 0, ll _s = 0) : val(_val), s(_s) {}

        Node operator + (const Node& other) const
        {
            return { (val * pow2[other.s] + other.val) % MOD, s + other.s };
        }
    } nodes[4*SZ];

    int u,v;

    void build(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = {a[lo],1};
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void updatePos(int id, int lo, int hi, int pos)
    {
        if(lo > pos || hi < pos) return;
        if(lo == hi)
        {
            nodes[id] = {0, 0};
            return;
        }
        int mid = (lo + hi) / 2;
        updatePos(2*id, lo, mid, pos);
        updatePos(2*id+1, mid+1, hi, pos);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    Node queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
    }

    Node query(int u, int v)
    {
        SegTree::u = u;
        SegTree::v = v;
        return queryR(1, 1, n);
    }

    int getR(int id, int lo, int hi, int pos)
    {
        if(lo == hi) return lo;
        int mid = (lo + hi) / 2;
        if(nodes[2*id].s >= pos) return getR(2*id, lo, mid, pos);
        return getR(2*id+1, mid+1, hi, pos - nodes[2*id].s);
    }

    int get(int pos)
    {
        return getR(1, 1, n, pos);
    }
} seg;

int main()
{
    init();
    cin >> s;
    n = s.length();
    for(int i = 0; i < s.length(); i++)
    {
        a[i+1] = s[i] - '0';
        //cout << i+1 << " " << a[i+1] << '\n';
    }
    pow2[0] = 1;
    for(int i = 1; i < SZ; i++)
    {
        pow2[i] = pow2[i-1] * 2LL;
        pow2[i] %= MOD;
        //if(i > 6) continue;
        //cout << i << " " << pow2[i] << '\n';
    }
    cin >> t;
    seg.build(1, 1, n);
    while(t--)
    {
        char c;
        cin >> c;
        if(c == '-')
        {
            int pos;
            cin >> pos;
            pos = seg.get(pos);
            seg.updatePos(1, 1, n, pos);
            //cout << "1 " << pos << '\n';
        } else
        {
            int lo1, lo2, k, hi1, hi2;
            cin >> lo1 >> lo2 >> k;
            hi1 = lo1 + k - 1;
            hi2 = lo2 + k - 1;
            lo1 = seg.get(lo1);
            lo2 = seg.get(lo2);
            hi1 = seg.get(hi1);
            hi2 = seg.get(hi2);
            ll val1 = seg.query(lo1, hi1).val, val2 = seg.query(lo2,hi2).val;
//            cout << lo1 << "-" << hi1 << " " << lo2 << "-" << hi2 << ' ';
//            cout << val1 << " " << val2 << " ";
            cout << (val1 == val2 ? "YES" : "NO") << '\n';
        }
    }
}
