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
    ll sum, prefix, suffix, ans;
    Node(ll _sum = 0, ll _prefix = 0, ll _suffix = 0, ll _ans = 0)
    {
        sum = _sum;
        prefix = _prefix;
        suffix = _suffix;
        ans = _ans;
    }

    Node operator + (const Node& other) const
    {
        return {sum + other.sum, max(prefix,sum+other.prefix), max(other.sum+suffix, other.suffix), max({ans,other.ans,suffix + other.prefix}) };
    }
};

ll n,m,a[SZ];
Node seg[4*SZ];

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = { a[lo], a[lo], a[lo], a[lo] };
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
        seg[id] = {v,v,v,v};
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
        return {0,-INFLL,-INFLL,-INFLL};
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
    cout << query(1,1,n,1,n).ans << '\n';
    while(m--)
    {
        int i,v;
        cin >> i >> v;
        update(1,1,n,i,v);
        cout << query(1,1,n,1,n).ans << '\n';
    }
}
