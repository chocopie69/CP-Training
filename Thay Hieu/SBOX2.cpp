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

const int SZ = 1e5+5;
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
    ll val, lazy;
    Node(ll _val = 0, ll _lazy = 0)
    {
        val = _val;
        lazy = _lazy;
    }

    Node operator + (const Node& other) const
    {
        return {val + other.val, 0};
    }
};

Node seg[4*SZ];

void updateLazy(int id, int lo, int hi)
{
    ll t = seg[id].lazy;
    seg[id].lazy = 0;
    if(lo == hi) return;
    seg[2*id].val += t;
    seg[2*id].lazy += t;
    seg[2*id+1].val += t;
    seg[2*id+1].lazy += t;
}

void update(int id, int lo, int hi, int u, int v, ll val)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        seg[id].val += val;
        seg[id].lazy += val;
        return;
    }
    updateLazy(id,lo,hi);
    int mid = (lo + hi) / 2;
    update(2*id, lo, mid, u, v, val);
    update(2*id+1, mid+1, hi, u, v, val);
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi, int pos)
{
    updateLazy(id, lo, hi);
    int mid = (lo + hi) / 2;
    if(lo == hi) return seg[id];
    if(pos <= mid) return query(2*id, lo, mid, pos);
    return query(2*id+1, mid+1, hi, pos);
}

int n,q;

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int lo, hi;
            ll d;
            cin >> lo >> hi >> d;
            update(1,1,n,lo,hi,d);
        } else
        {
            int x;
            cin >> x;
            cout << query(1,1,n,x).val << '\n';
        }
    }
}
