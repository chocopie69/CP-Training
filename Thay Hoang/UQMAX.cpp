#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "UQMAX"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Node
{
    ll val, cnt, lazy;
    Node(ll _val = 0, ll _cnt = 0, ll _lazy = 0)
    {
        val = _val;
        cnt = _cnt;
        lazy = _lazy;
    }

    Node operator + (const Node& other) const
    {
        if(val > other.val)
        {
            return {val,cnt,0};
        } else if(val < other.val)
        {
            return {other.val,other.cnt,0};
        }
        return {val,cnt+other.cnt,0};
    }
};

ll n,m,i,j,x;
char c;
Node st[4*SZ];
ll val;
int u,v;

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        st[id].cnt = 1;
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    st[id] = st[2*id] + st[2*id+1];
}

void doBuild()
{
    build(1,1,n);
}

void push(int id)
{
    ll cur = st[id].lazy;
    st[2*id].val += cur;
    st[2*id].lazy += cur;
    st[2*id+1].val += cur;
    st[2*id+1].lazy += cur;
    st[id].lazy = 0;
}

void update(int id, int lo, int hi)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    push(id);
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid);
    update(2*id+1,mid+1,hi);
    st[id] = st[2*id] + st[2*id+1];
}

Node query(int id, int lo, int hi)
{
    if(lo > v || hi < u)
    {
        return {-INFLL,0,0};
    }
    if(lo >= u && hi <= v)
    {
        return st[id];
    }
    push(id);
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid) + query(2*id+1,mid+1,hi);
}

void doUpdate(int u, int v, ll val)
{
    ::u = u;
    ::v = v;
    ::val = val;
    update(1,1,n);
}

void doQuery(int u,int v)
{
    ::u = u;
    ::v = v;
    Node res = query(1,1,n);
    cout << res.val << " " << res.cnt << '\n';
}

int main()
{
    init();
    cin >> n >> m;
    doBuild();
    while(m--)
    {
        cin >> c >> i >> j;
        if(c == 'I')
        {
            cin >> x;
            doUpdate(i,j,x);
        } else
        {
            doQuery(i,j);
        }
    }
}
