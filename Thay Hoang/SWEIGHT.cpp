#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SWEIGHT"

using namespace std;

const int SZ = 8e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> nen;

ll n,a[SZ], fl[SZ], fr[SZ], res = 1;

ll st[SZ], val;
int u,v,pos;

void update(int id, int lo, int hi)
{
    if(lo == hi)
    {
        st[id] = max(st[id],val);
        return;
    }
    int mid = (lo + hi) / 2;
    if(mid >= pos)
    {
        update(2*id,lo,mid);
    } else
    {
        update(2*id+1,mid+1,hi);
    }
    st[id] = max(st[2*id],st[2*id+1]);
}

void doUpdate(int pos, ll val)
{
    ::pos = pos;
    ::val = val;
    update(1,1,n);
}

ll query(int id, int lo, int hi)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return st[id];
    int mid = (lo + hi) / 2;
    return max(query(2*id,lo,mid),query(2*id+1,mid+1,hi));
}

ll getMax(int u, int v)
{
    if(u > v) return 0;
    ::u = u;
    ::v = v;
    return query(1,1,n);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.erase(unique(all(nen)),nen.end());
    for(int i = 1; i <= n; i++)
    {
        a[i] = (lower_bound(all(nen),a[i]) - nen.begin()) + 1;
    }
    int prev = 0;
    fl[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > prev)
        {
            fl[i] = fl[i-1] + 1;
        } else
        {
            fl[i] = 1;
        }
        prev = a[i];
    }
    prev = n+1;
    fr[n+1] = 0;
    for(int i = n; i >= 1; i--)
    {
        res = max(res,fl[i] + getMax(a[i]+1,n));
        if(a[i] < prev)
        {
            fr[i] = fr[i+1] + 1;
        } else
        {
            fr[i] = 1;
        }
        doUpdate(a[i],fr[i]);
        prev = a[i];
    }
    cout << res;
}
