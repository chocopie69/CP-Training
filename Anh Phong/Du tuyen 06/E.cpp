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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ];
ll res = 0;

struct SegTree
{
    struct Node
    {
        ll mn, cnt, lazy;
        Node(ll _mn = 0, ll _cnt = 0, ll _lazy = 0) : mn(_mn), cnt(_cnt), lazy(_lazy) {}

        Node operator + (const Node& other) const
        {
            if(mn < other.mn) return {mn, cnt, 0};
            else if(mn > other.mn) return {other.mn, other.cnt, 0};
            return {mn, cnt + other.cnt, 0};
        }
    } nodes[4*SZ];

    void build(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = {lo, 1};
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    void down(int id, int lo, int hi)
    {
        ll t = nodes[id].lazy;
        nodes[id].lazy = 0;
        nodes[2*id].mn += t;
        nodes[2*id].lazy += t;
        nodes[2*id+1].mn += t;
        nodes[2*id+1].lazy += t;
    }

    int u,v;
    ll val;

    void updateR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return;
        if(lo >= u && hi <= v)
        {
            nodes[id].mn += val;
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

vector<int> v1, v2;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x] = y;
    }
    seg.build(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        while(!v1.empty() && a[v1.back()] > a[i])
        {
            int hi = v1.back();
            ll dif = a[i] - a[v1.back()];
            v1.pop_back();
            int lo = v1.empty() ? 1 : v1.back() + 1;
            seg.update(lo, hi, -dif);
        }
        v1.pb(i);
        while(!v2.empty() && a[v2.back()] < a[i])
        {
            int hi = v2.back();
            ll dif = a[i] - a[v2.back()];
            v2.pop_back();
            int lo = v2.empty() ? 1 : v2.back() + 1;
            seg.update(lo, hi, dif);
        }
        v2.pb(i);
        if(seg.nodes[1].mn == i) res += seg.nodes[1].cnt;
    }
    cout << res;
}

