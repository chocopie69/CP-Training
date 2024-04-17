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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,a[SZ], sum[2][SZ];
vector<int> vec1, vec2;
ll res = 0, x[SZ];

struct SegTree
{
    struct Node
    {
        int cnt, lazy;
        Node(int _cnt = 0, int _lazy = 0) : cnt(_cnt), lazy(_lazy) {}

        Node operator + (const Node& other) const
        {
            return {cnt + other.cnt, 0};
        }
    } nodes[4*SZ];

    void build(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = { 1, 0 };
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void down(int id, int lo, int hi)
    {
        int mid = (lo + hi) / 2, len1 = mid - lo + 1, len2 = hi - mid;
        ll t = nodes[id].lazy;
        nodes[id].lazy = 0;
        nodes[2*id].cnt = ( t % 2 == 0 ? nodes[2*id].cnt : len1 - nodes[2*id].cnt );
        nodes[2*id].lazy += t;
        nodes[2*id+1].cnt = ( t % 2 == 0 ? nodes[2*id+1].cnt : len2 - nodes[2*id+1].cnt );
        nodes[2*id+1].lazy += t;
    }

    int u,v;
    ll val;

    void updateR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return;
        if(lo >= u && hi <= v)
        {
            nodes[id].cnt = ( val % 2 == 0 ? nodes[id].cnt : (hi - lo + 1) - nodes[id].cnt );
            nodes[id].lazy += val;
            return;
        }
        down(id, lo, hi);
        int mid = (lo + hi) / 2;
        updateR(2*id, lo, mid);
        updateR(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void update(int u, int v, ll val)
    {
        SegTree::u = u;
        SegTree::v = v;
        SegTree::val = val;
        updateR(1, 1, n);
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
    seg.build(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        while(!vec1.empty() && a[vec1.back()] > a[i])
        {
            int hi = vec1.back();
            vec1.pop_back();
            ll dif = a[hi] - a[i];
            int lo = vec1.empty() ? 1 : vec1.back() + 1;
            seg.update(lo, hi, -dif);
        }
        vec1.pb(i);
        while(!vec2.empty() && a[vec2.back()] < a[i])
        {
            int hi = vec2.back();
            vec2.pop_back();
            ll dif = a[i] - a[hi];
            int lo = vec2.empty() ? 1 : vec2.back() + 1;
            seg.update(lo, hi, dif);
        }
        vec2.pb(i);
        res += seg.nodes[1].cnt - (n - i);
    }
    cout << res;
}

