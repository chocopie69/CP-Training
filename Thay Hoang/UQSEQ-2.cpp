#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "UQSEQ"

using namespace std;

const int SZ = 4e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m, pos;
ll i,j,x, seg[SZ], u, v, val, lazy[SZ];
char c;

void push(int id)
{
    ll t = lazy[id];
    seg[2*id] += t;
    seg[2*id+1] += t;
    lazy[2*id] += t;
    lazy[2*id+1] += t;
    lazy[id] = 0;
}

void update(int id, int lo, int hi)
{
    if(v < lo || u > hi) return;
    if(lo >= u && hi <= v)
    {
        seg[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid);
    update(2*id+1,mid+1,hi);
    seg[id] = max(seg[2*id],seg[2*id+1]);
}

ll query(int id, int lo, int hi)
{
    if(lo == hi) return seg[id];
    push(id);
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        return query(2*id,lo,mid);
    } else
    {
        return query(2*id+1,mid+1,hi);
    }
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> c >> i;
        if(c == 'I')
        {
            cin >> j >> x;
            u = i;
            v = j;
            val = x;
            update(1,1,n);
        } else
        {
            pos = i;
            cout << query(1,1,n) << '\n';
        }
    }
}
