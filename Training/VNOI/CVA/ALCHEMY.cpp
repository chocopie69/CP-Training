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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, d[SZ];
string s, u, v, a, b;
map<string,int> mp;

vector<int> adj[SZ];

bool vis[SZ];

queue<int> qu;

void bfs(int s)
{
    d[s] = 0;
    qu.push(s);
    vis[s] = true;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(vis[v]) continue;
            d[v] = d[u] + 1;
            vis[v] = true;
            qu.push(v);
        }
    }
}

int main()
{
    init();
    cin >> n;
    int id = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> s >> v;
        if(mp.find(u) == mp.end())
        {
            id++;
            mp[u] = id;
        }
        if(mp.find(v) == mp.end())
        {
            id++;
            mp[v] = id;
        }
        adj[mp[u]].push_back(mp[v]);
        //cout << u << " " << v << '\n';
    }
    cin >> a >> b;
    //cout << mp[a] << " " << mp[b] << '\n';
    if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
    {
        //cout << a << " " << b;
        cout << -1;
        return 0;
    }
    memset(d,-1,sizeof(d));
    bfs(mp[a]);
    cout << d[mp[b]];
}
