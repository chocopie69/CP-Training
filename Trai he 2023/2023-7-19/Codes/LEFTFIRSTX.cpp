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

ll n,m,a[SZ],seg[4*SZ];

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = a[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = max(seg[2*id],seg[2*id+1]);
}

void update(int id, int lo, int hi, int pos, ll v)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id] = v;
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos,v);
    update(2*id+1,mid+1,hi,pos,v);
    seg[id] = max(seg[2*id],seg[2*id+1]);
}

ll query(int id, int lo, int hi, ll val, int pos)
{
    if(hi < pos) return -1;
    if(lo == hi)
        return lo;
    int mid = (lo + hi) / 2;
    ll res = -1;
    if(seg[2*id] >= val)
    {
        res = query(2*id,lo,mid,val,pos);
    }
    if(seg[2*id+1] >= val && res == -1)
    {
        res = query(2*id+1,mid+1,hi,val,pos);
    }
    return res;
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
        int t,i,v,x;
        cin >> t;
        if(t == 1)
        {
            cin >> i >> v;
            update(1,1,n,i,v);
        } else
        {
            cin >> x >> i;
            cout << query(1,1,n,x,i) << '\n';
        }
    }
}

