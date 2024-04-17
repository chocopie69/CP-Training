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

ll n,k, a[SZ];

struct FenwickTree
{
    ll nodes[SZ];

    void update(int pos)
    {
        while(pos <= n)
        {
            nodes[pos]++;
            pos += pos & (-pos);
        }
    }

    ll query(int pos)
    {
        ll sum = 0;
        while(pos > 0)
        {
            sum += nodes[pos];
            pos -= pos & (-pos);
        }
        return sum;
    }
} ft;

struct SegmentTree
{
    pll nodes[4*SZ];

    pll get(pll x, pll y)
    {
        if(x.fi != y.fi) return (x.fi > y.fi ? x : y);
        if(x.se > y.se) swap(x,y);
        return x;
    }

    void buildR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = { a[lo], lo };
            return;
        }
        int mid = (lo + hi) / 2;
        buildR(2*id, lo, mid);
        buildR(2*id+1, mid+1, hi);
        nodes[id] = get(nodes[2*id],nodes[2*id+1]);
    }

    void build()
    {
        buildR(1, 1, n);
    }

    int pos;

    void updateR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = {-1,0};
            return;
        }
        int mid = (lo + hi) / 2;
        if(pos <= mid) updateR(2*id, lo, mid);
        else updateR(2*id+1, mid+1, hi);
        nodes[id] = get(nodes[2*id],nodes[2*id+1]);
    }

    void update(int pos)
    {
        SegmentTree::pos = pos;
        updateR(1, 1, n);
    }

    int u,v;

    pll queryR(int id, int lo, int hi)
    {
        if(lo > v || hi < u) return {-1,0};
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return get(queryR(2*id, lo, mid),queryR(2*id+1, mid+1, hi));
    }

    pll query(int u, int v)
    {
        SegmentTree::u = u;
        SegmentTree::v = v;
        return queryR(1, 1, n);
    }
} st;

vector<ll> swapped;
bool vis[SZ];

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    st.build();
    while(k > 0)
    {
        int lo = 1, hi = n, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(mid - ft.query(mid) - 1 <= k)
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        if(hi - ft.query(hi) - 1 > k) break;
        pll best = st.query(1, hi);
        if(best.se == 0) break;
        swapped.push_back(best.first);
        vis[best.second] = true;
        k -= best.second - ft.query(best.second) - 1;
        ft.update(best.second);
        st.update(best.second);
    }
    for(ll x : swapped) cout << x << " ";
    for(int i = 1; i <= n; i++)
        if(!vis[i]) cout << a[i] << " ";
}
