/// https://oj.vnoi.info/problem/bedao_g13_c

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

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ], p[SZ], res = -INFLL;
stack<ll> st;

bool exist[SZ];

struct DSU
{
    ll par[SZ], s[SZ], sum[SZ], prefix[SZ], suffix[SZ], best[SZ];

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
            sum[i] = a[i];
            prefix[i] = a[i];
            suffix[i] = a[i];
            best[i] = a[i];
        }
    }

    ll get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(u > v) swap(u,v);
        par[v] = u;
        //cout << u << " " << v << " " << best[u] << " " << best[v] << " " << suffix[u] << " " << prefix[v] << '\n';
        best[u] = max({best[u], best[v], suffix[u] + prefix[v] });
        prefix[u] = max(prefix[u], sum[u] + prefix[v]);
        suffix[u] = max(suffix[v], sum[v] + suffix[u]);
        sum[u] += sum[v];
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    dsu.init(n);
    for(int i = n; i >= 1; i--)
    {
        if(exist[p[i] - 1]) dsu.join(p[i] - 1, p[i]);
        if(exist[p[i] + 1]) dsu.join(p[i],p[i] + 1);
        exist[p[i]] = true;
        int u = dsu.get(p[i]);
        res = max(res, dsu.best[u]);
        st.push(res);
    }
    while(!st.empty())
    {
        cout << st.top() << '\n';
        st.pop();
    }
}
