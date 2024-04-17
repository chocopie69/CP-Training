#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LOVESTORY"

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

ll n,q,k,a[SZ], res = 0;
vector<ll> nen, adj[SZ];

ll h[SZ], up[SZ][19];

void dfs(int u) {
    for (ll v : adj[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        for (int j = 1; j <= 18; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);

        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1)
                u = up[u][j];
    }
    if (u == v) return u;

    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

vector<ll> vec;
ll cnt[SZ];
bool vis[SZ];

namespace sub1
{
    void solve()
    {
        while(q--)
        {
            bool flag = false;
            ll u,v;
            cin >> u >> v;
            u = (u + res*k) % n + 1;
            v = (v + res*k) % n + 1;
            ll p = lca(u,v);
            //cout << u << " " << v << " " << p << " - ";
            //cout << u << " " << v << '\n';
            while(true)
            {
                if(!vis[a[u]])
                {
                    vec.push_back(a[u]);
                    vis[a[u]] = true;
                }
                cnt[a[u]]++;
                if(u == p) break;
                u = up[u][0];
            }
            while(v != p)
            {
                if(!vis[a[v]])
                {
                    vec.push_back(a[v]);
                    vis[a[v]] = true;
                }
                cnt[a[v]]++;
                v = up[v][0];
            }
            sort(all(vec),greater<ll>());
            ll sum = 0;
            res = nen[vec[0]-1] + 1;
            int pos = -1;
    //        for(ll x : vec)
    //        {
    //            sum += cnt[x];
    //            if(sum % 2 == 1)
    //            {
    //                flag = true;
    //                break;
    //            } else res = nen[x-1];
    //            //cout << x << " " << nen[x-1] << " " << cnt[x] << '\n';
    //        }
            for(int i = 0; i < vec.size(); i++)
            {
                ll x = vec[i];
                sum += cnt[x];
                if(sum % 2 == 1)
                {
                    flag = true;
                    break;
                } else
                {
                    res = nen[x-1];
                    pos = i;
                }
            }
            if(!flag) res = 1;
            if(flag && pos != -1)
            {
                res = nen[vec[pos + 1]-1] + 1;
            }
            while(!vec.empty())
            {
                cnt[vec.back()] = 0;
                vis[vec.back()] = false;
                vec.pop_back();
            }
            //cout << "- ";
            cout << res << '\n';
        }
    }
}

namespace sub2
{
    void solve()
    {
        while(q--)
        {
            bool flag = false;
            ll u,v;
            cin >> u >> v;
            u = (u + res*k) % n + 1;
            v = (v + res*k) % n + 1;
            //cout << u << " " << v << " " << lca(u,v) << '\n';
            ll p = lca(u,v);
            ll x = h[u] + h[v] - 2 * h[p] + 1;
            if(x % 2 == 0) {
                res = 1;
            }
            else res = nen[a[1]-1] + 1;
            cout << res << '\n';
        }
    }
}

bool isSub2 = true;

int main()
{
    init();
    cin >> n >> q >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nen.push_back(a[i]);
        if(i > 1 && a[i] != a[i-1]) isSub2 = false;
    }
    sort(all(nen));
    for(int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(nen), a[i]) - nen.begin() + 1;
        //cout << a[i] << " " << nen[a[i] - 1] << '\n';
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if(isSub2)
        sub2::solve();
    else if(n <= 50000)
        sub1::solve();
}

/*
6 3 0
7 7 7 7 7 7
1 2
1 3
2 4
2 5
4 6
1 3
1 2
2 3
*/
