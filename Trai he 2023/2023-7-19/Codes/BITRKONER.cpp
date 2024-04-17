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
        return {val + other.val,0};
    }
};

ll n,m,u,v,x,pos;
Node seg[4*SZ];

void down(int id, int lo, int hi)
{
    ll t = seg[id].lazy, mid = (lo + hi) / 2, len1 = mid - lo + 1, len2 = hi - mid;
    if(t == 0) return;
    seg[2*id].val = len1 - seg[2*id].val;
    seg[2*id].lazy ^= t;
    seg[2*id+1].val = len2 - seg[2*id+1].val;
    seg[2*id+1].lazy ^= t;
    seg[id].lazy = 0;
}

void update(int id, int lo, int hi)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        seg[id].val = (hi - lo + 1) - seg[id].val;
        seg[id].lazy ^= 1;
        return;
    }
    down(id,lo,hi);
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid);
    update(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

ll query(int id, int lo, int hi, int pos)
{
    if(lo == hi)
        return lo;
    down(id,lo,hi);
    int mid = (lo + hi) / 2;
    if(seg[2*id].val >= pos)
    {
        return query(2*id,lo,mid, pos);
    } else if(seg[2*id+1].val >= pos - seg[2*id].val)
        return query(2*id+1,mid+1,hi, pos - seg[2*id].val);
    return -1;
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        ll type;
        cin >> type;
        if(type == 1)
        {
            cin >> u >> v;
            update(1,1,n);
        } else
        {
            ll k;
            cin >> k;
            cout << query(1,1,n,k) << '\n';
        }
    }
}
