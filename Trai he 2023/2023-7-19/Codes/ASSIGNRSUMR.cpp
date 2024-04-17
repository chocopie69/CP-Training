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
        return {val + other.val,-1};
    }
};

ll n,m,u,v,x,pos;
Node seg[4*SZ];

void down(int id, int lo, int hi)
{
    ll t = seg[id].lazy, mid = (lo + hi) / 2, len1 = mid - lo + 1, len2 = hi - mid;
    if(t == -1) return;
    seg[2*id].val = t * len1;
    seg[2*id].lazy = t;
    seg[2*id+1].val = t * len2;
    seg[2*id+1].lazy = t;
    seg[id].lazy = -1;
}

void update(int id, int lo, int hi)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        seg[id].val = x * (hi - lo + 1);
        seg[id].lazy = x;
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
    if(lo > v || hi < u) return {0,0};
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

