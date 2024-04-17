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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 5e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q, lf[SZ], rt[SZ];
pll a[SZ];
stack<int> st;
ll res[SZ];

struct Segment
{
    int lo, hi;
    ll w;
    Segment(int _lo = 0, int _hi = 0, ll _w = 0) : lo(_lo), hi(_hi), w(_w) {}

    bool operator < (const Segment& other) const
    {
        return hi < other.hi;
    }
};

struct Query
{
    int lo, hi, id;
    Query(int _lo = 0, int _hi = 0, int _id = 0) : lo(_lo), hi(_hi), id(_id) {}

    bool operator < (const Query& other) const
    {
        return hi < other.hi;
    }
};

Query queries[SZ];

vector<Segment> segments;

struct FenwickTree
{
    ll mn[SZ];

    void init()
    {
        for(int i = 1; i < SZ; i++) mn[i] = INFLL;
    }

    void update(int pos, ll val)
    {
        while(pos > 0)
        {
            mn[pos] = min(mn[pos], val);
            pos -= (pos & (-pos));
        }
    }

    ll query(int pos)
    {
        ll ans = INFLL;
        while(pos <= n)
        {
            ans = min(ans, mn[pos]);
            pos += (pos & (-pos));
        }
        return ans;
    }
} ft;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        while(!st.empty() && a[st.top()].se > a[i].se) st.pop();
        if(!st.empty())
        {
            int x = st.top();
            segments.push_back({ x, i, (a[i].fi - a[x].fi) * (a[i].se + a[x].se) });
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n; i >= 1; i--)
    {
        while(!st.empty() && a[st.top()].se > a[i].se) st.pop();
        if(!st.empty())
        {
            int x = st.top();
            segments.push_back({ i, x, (a[x].fi - a[i].fi) * (a[i].se + a[x].se) });
        }
        st.push(i);
    }
    sort(all(segments));
//    for(Segment x : segments)
//    {
//        cout << x.lo << " " << x.hi << " " << x.w << '\n';
//    }
    for(int i = 1; i <= q; i++)
    {
        int lo,hi;
        cin >> lo >> hi;
        queries[i] = {lo,hi,i};
    }
    sort(queries + 1, queries + q + 1);
    int j = 0;
    ft.init();
    for(int i = 1; i <= q; i++)
    {
        while(j < segments.size() && segments[j].hi <= queries[i].hi)
        {
            ft.update(segments[j].lo, segments[j].w);
            //cout << segments[j].w << '\n';
            j++;
        }
        res[queries[i].id] = ft.query(queries[i].lo);
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}

/*
2 1
-1000000000 1000000000
1000000000 1000000000
1 2
*/


