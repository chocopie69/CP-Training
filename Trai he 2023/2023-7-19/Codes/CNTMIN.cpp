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
    ll val, cnt;
    Node(ll _val = 0, ll _cnt = 0)
    {
        val = _val;
        cnt = _cnt;
    }

    Node operator + (const Node& other) const
    {
        ll x;
        if(val == other.val)
            x = cnt + other.cnt;
        else
            x = (val < other.val ? cnt : other.cnt);
        return {min(val,other.val), x};
    }
};

ll n,m,a[SZ];
Node seg[4*SZ];

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = {a[lo],1};
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(int id, int lo, int hi, int pos, ll v)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id] = {v,1};
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos,v);
    update(2*id+1,mid+1,hi,pos,v);
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u)
        return {INFLL,0};
    if(lo >= u && hi <= v)
        return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid,u,v) + query(2*id+1,mid+1,hi,u,v);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    while(m--)
    {
        int t,u,v;
        cin >> t >> u >> v;
        if(t == 1)
        {
            update(1,1,n,u,v);
        } else
        {
            Node ans = query(1,1,n,u,v);
            cout << ans.val << " " << ans.cnt << '\n';
        }
    }
}
