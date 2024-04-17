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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Query
{
    int lo, hi, k, id;
    Query(int _lo = 0, int _hi = 0, int _k = 0, int _id = 0) : lo(_lo), hi(_hi), k(_k), id(_id) {}

    bool operator < (const Query& other) const
    {
        return hi < other.hi;
    }
} b[SZ];

struct SegTree
{
    int nodes[4*SZ], lazy[4*SZ];

    void down(int id)
    {
        int t = lazy[id];
        lazy[id] = 0;
        nodes[2*id] = max(nodes[2*id],t);
        lazy[2*id] = max(lazy[2*id], t);
        nodes[2*id+1] = max(nodes[2*id+1],t);
        lazy[2*id+1] = max(lazy[2*id+1],t);
    }

    void update(int id, int lo, int hi, int u, int v, int val)
    {
        if(lo > v || hi < u) return;
        if(lo >= u && hi <= v)
        {
            nodes[id] = max(nodes[id], val);
            lazy[id] = max(lazy[id], val);
            return;
        }
        down(id);
        int mid = (lo + hi) / 2;
        update(2*id, lo, mid, u, v, val);
        update(2*id+1, mid+1, hi, u, v, val);
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    int query(int id, int lo, int hi, int u, int v)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v)
        {
            //cout << "query " << lo << " " << hi << " " << nodes[id] << '\n';
            return nodes[id];
        }
        down(id);
        int mid = (lo + hi) / 2;
        return max(query(2*id,lo, mid , u, v), query(2*id+1, mid+1, hi, u, v));
    }
} seg;

int n,m, a[SZ], res[SZ];
stack<int> st;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i].lo >> b[i].hi >> b[i].k;
        b[i].id = i;
    }
    sort(b + 1, b + m + 1);
    int j = 1;
    st.push(0);
    for(int i = 1; i <= m; i++)
    {
        int lo = b[i].lo, hi = b[i].hi, k = b[i].k, id = b[i].id;
        while(j <= hi)
        {
            while(st.size() > 1 && a[st.top()] <= a[j]) st.pop();
            if(st.size() > 1)
            {
                int cur = st.top();
                st.pop();
                seg.update(1, 1, n, st.top() + 1, cur, a[j] + a[cur]);
                //cout << "update " << st.top() + 1 << " " << cur << " " << a[j] + a[cur] << '\n';
                st.push(cur);
            }
            st.push(j);
            j++;
        }
        ll trol = seg.query(1, 1, n, lo, hi);
        //cout << lo << " " << hi << " " << k << " " << trol << '\n';
        res[id] = (trol <= k ? 1 : 0);
    }
    for(int i = 1; i <= m; i++)
    {
        cout << res[i] << '\n';
    }
}

