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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Node
{
    ll val,lazy;
    Node(ll _val = 0, ll _lazy = 0)
    {
        val = _val;
        lazy = _lazy;
    }
    Node operator + (const Node& other) const
    {
        return {( (val % MOD) + (other.val % MOD)) % MOD,1};
    }
};

ll n,m,u,v,x,pos;
Node seg[4*SZ];

void down(int id, int lo, int hi)
{
    ll t = seg[id].lazy % MOD;
    seg[2*id].val = ( (seg[2*id].val % MOD) * t) % MOD;
    seg[2*id].lazy = ( (seg[2*id].lazy % MOD) * t) % MOD;
    seg[2*id+1].val = ( (seg[2*id+1].val % MOD) * t) % MOD;
    seg[2*id+1].lazy = ( (seg[2*id+1].lazy % MOD )* t) % MOD;
    seg[id].lazy = 1LL;
}

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = {1LL,1LL};
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(int id, int lo, int hi)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        seg[id].val *= x;
        seg[id].lazy *= x;
        return;
    }
    down(id,lo,hi);
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid);
    update(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi)
{
    if(lo > v || hi < u) return {0,1};
    if(lo >= u && hi <= v)
        return seg[id];
    down(id,lo,hi);
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid) + query(2*id+1,mid+1,hi);
}

int main()
{
    init();
    cin >> n >> m;
    build(1,1,n);
    while(m--)
    {
        ll type;
        cin >> type;
        if(type == 1)
        {
            cin >> u >> v >> x;
            update(1,1,n);
        } else
        {
            cin >> u >> v;
            cout << query(1,1,n).val << '\n';
        }
    }
}
