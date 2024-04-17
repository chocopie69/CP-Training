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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
pll a[SZ];

bool cmp(pll x, pll y)
{
    if(x.se != y.se) return x.se < y.se;
    return x.fi < y.fi;
}

struct SegmentTree
{
    int pos;
    ll val;

    ll nodes[4*SZ];

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) updateR(2*id, lo, mid);
        else updateR(2*id+1, mid+1, hi);
        nodes[id] = max(nodes[2*id],nodes[2*id+1]);
    }

    void update(int pos, ll val)
    {
        SegmentTree::pos = pos;
        SegmentTree::val = val;
        updateR(1, 1, n);
    }

    int u, v;

    ll queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return -INFLL;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return max(queryR(2*id,lo,mid),queryR(2*id+1,mid+1,hi));
    }

    ll query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} st;

ll dp[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        int lo = 1, hi = i-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(a[mid].se <= a[i].fi)
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        int j = hi;
        dp[i] = max(dp[i-1], dp[j] + a[i].se - a[i].fi );
        ll best = st.query(j+1,i-1);
        dp[i] = max(dp[i], best + a[i].fi + a[i].se);
        st.update(i, dp[i] - 2*a[i].se );
    }
    cout << dp[n];
}
