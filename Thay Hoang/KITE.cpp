#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "KITE"

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

int n,a[SZ],st[4*SZ], b[SZ];

void update(int id, int lo, int hi, int idx)
{
    if(lo == hi)
    {
        st[id]++;
        return;
    }
    int mid = (lo + hi) / 2;
    if(idx <= mid)
    {
        update(2*id,lo,mid,idx);
    } else
    {
        update(2*id+1,mid+1,hi,idx);
    }
    st[id] = st[2*id] + st[2*id+1];
}

int query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return st[id];
    int mid = (lo + hi) / 2;
    return query(2*id, lo, mid, u , v) + query(2*id+1, mid+1, hi, u, v);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for(int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b+1,b+n+1,a[i]) - b;
        cout << query(1,1,n,pos+1,n) + 1 << '\n';
        update(1,1,n,pos);
    }
}
