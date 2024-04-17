#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "QUERY"

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
    ll val, lazy;
    Node(ll _val = 0, ll _lazy = 0)
    {
        val = _val;
        lazy = _lazy;
    }
    Node operator + (const Node& other) const
    {
        return {val+other.val,0};
    }
};

ll n,a[SZ],q;
Node seg[4*SZ][6];

void down(int id, int lo, int hi,int p)
{
    int mid = (lo + hi) / 2, len1 = mid-lo+1, len2 = hi-mid+1;
    ll t = seg[id][p].lazy;
    seg[id][p].lazy = 0;
    seg[2*id][p].val += t*len1;
    seg[2*id][p].lazy += t;
    seg[2*id+1][p].val += t*len2;
    seg[2*id+1][p].lazy += t;
}

void update(int id, int lo, int hi, int u, int v,int p)
{
    if(lo > v || hi < u) return;
    if(lo >= u && hi <= v)
    {
        seg[id][p].val += hi-lo+1;
        seg[id][p].lazy++;
        return;
    }
    down(id,lo,hi,2);
    down(id,lo,hi,3);
    down(id,lo,hi,5);
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,u,v,p);
    update(2*id+1,mid+1,hi,u,v,p);
    seg[id][p] = seg[2*id][p] + seg[2*id+1][p];
}

void update2(int id, int lo, int hi, int pos)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id][2] = {0,0};
        seg[id][3] = {0,0};
        seg[id][5] = {0,0};
        return;
    }
    down(id,lo,hi,2);
    down(id,lo,hi,3);
    down(id,lo,hi,5);
    int mid = (lo + hi) / 2;
    update2(2*id,lo,mid,pos);
    update2(2*id+1,mid+1,hi,pos);
    seg[id][2] = seg[2*id][2] + seg[2*id+1][2];
    seg[id][3] = seg[2*id][3] + seg[2*id+1][3];
    seg[id][5] = seg[2*id][5] + seg[2*id+1][5];
}

Node query(int id, int lo, int hi, int pos,int p)
{
    if(lo == hi) return seg[id][p];
    down(id,lo,hi,2);
    down(id,lo,hi,3);
    down(id,lo,hi,5);
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        return query(2*id,lo,mid,pos,p);
    }
    return query(2*id+1,mid+1,hi,pos,p);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int lo,hi,p;
            cin >> lo >> hi >> p;
            update(1,1,n,lo,hi,p);
        } else
        {
            int i,v;
            cin >> i >> v;
            a[i] = v;
            update2(1,1,n,i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        ll t2 = query(1,1,n,i,2).val, t3 = query(1,1,n,i,3).val, t5 = query(1,1,n,i,5).val;
        //cout << t2 << " " << t3 << " " << t5 << '\n';
        while(t2 > 0 && a[i] % 2 == 0) a[i] /= 2;
        while(t3 > 0 && a[i] % 3 == 0) a[i] /= 3;
        while(t5 > 0 && a[i] % 5 == 0) a[i] /= 5;
        cout << a[i] << " ";
    }
}
