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

int n,q;

ll seg[4*SZ];

void update(int id, int lo, int hi, int pos, ll val)
{
    int mid = (lo + hi) / 2;
    seg[id] += val;
    if(lo == hi) return;
    if(pos <= mid)
    {
        update(2*id, lo, mid, pos, val);
    } else
    {
        update(2*id+1, mid+1, hi, pos, val);
    }
}

ll query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid,u,v) + query(2*id+1,mid+1,hi,u,v);
}

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
            int x;
            ll d;
            cin >> x >> d;
            update(1,1,n,x,d);
        } else
        {
            int lo,hi;
            cin >> lo >> hi;
            cout << query(1,1,n,lo,hi) << '\n';
        }
    }
}
