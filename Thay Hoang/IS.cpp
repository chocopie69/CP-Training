#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "IS"

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

ll n,a[SZ],w[SZ],dp[SZ],st[SZ], val, mx, idx, maxA = 1;
int pos, u, v;
vector<int> res;

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
    update(1,1,maxA);
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
    ::u = u;
    ::v = v;
    return query(1,1,maxA);
}

void trace(int i, ll prev, ll x)
{
    if(i == 0 || x == 0) return;
    if(dp[i] == x && a[i] < prev)
    {
        res.push_back(i);
        trace(i-1,a[i],x-w[i]);
    } else
    {
        trace(i-1,prev,x);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    dp[1] = w[1];
    doUpdate(a[1],dp[1]);
    mx = dp[1];
    idx = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] != 1)
            dp[i] = getMax(1,a[i]-1) + w[i];
        else dp[i] = w[i];
        doUpdate(a[i],dp[i]);
        if(dp[i] > mx)
        {
            mx = dp[i];
            idx = i;
        }
    }
    trace(idx,INFLL, dp[idx]);
    cout << res.size() << '\n';
    while(!res.empty())
    {
        cout << res.back() << " ";
        res.pop_back();
    }
}

/*
10
1 2 3 6 4 100 101 6 7 8
11 22 33 66 44 55 999 66 77 88
*/
