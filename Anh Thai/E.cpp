#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, x, y;
ll a[SZ], res = 0;

struct SegTree
{
    ll nodes[4*SZ];

    void update(int pos, ll val, int id = 1, int lo = 1, int hi = n)
    {
        if(lo == hi)
        {
            nodes[id] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) update(pos, val, 2*id, lo, mid);
        else update(pos, val, 2*id+1, mid+1, hi);
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    ll query(int u, int v, int id = 1, int lo = 1, int hi = n)
    {
        if(lo > v || hi < u) return -INFLL;
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return max(query(u, v, 2*id, lo, mid), query(u, v, 2*id+1, mid+1, hi));
    }
} st;

int main()
{
    init();
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int lo = i - y, hi = i - x;
        ll mx = 0;
        if(hi > 0) mx = st.query(max(1, lo), hi);
        res = max(res, mx + a[i]);
        st.update(i, mx + a[i]);
    }
    cout << res;
}
