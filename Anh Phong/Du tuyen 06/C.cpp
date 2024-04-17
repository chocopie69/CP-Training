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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, num[SZ], low[SZ], timer = 0, cnt = 0, bcc = 0, s[SZ];
vector<int> adj[SZ], adj2[SZ], vec;
ll res = 0;

void dfs(int u, int prev)
{
    num[u] = low[u] = ++timer;
    vec.pb(u);
    ++cnt;
    for(int v : adj[u])
    {
        if(v == prev) continue;
        if(!num[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[u])
            {
                ++bcc;
                adj2[u].pb(bcc + n);
                int k = 0;
                do
                {
                    k = vec.back();
                    vec.pop_back();
                    adj2[bcc + n].pb(k);
                } while(k != v);
            }
        } else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

void dfs2(int u)
{
    s[u] = (u <= n);
    for(int v : adj2[u])
    {
        dfs2(v);
        s[u] += s[v];
        if(u > n) res -= 1LL*adj2[u].size() * s[v] * (s[v] - 1);
    }
    if(u > n) res -= 1LL*adj2[u].size() * (cnt - s[u]) * (cnt - s[u] - 1);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!num[i])
        {
            cnt = 0;
            dfs(i, i);
            res += 1LL*cnt*(cnt-1)*(cnt-2);
            dfs2(i);
        }
    }
    cout << res;
}

