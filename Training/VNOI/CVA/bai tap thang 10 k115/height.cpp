#include <bits/stdc++.h>
using namespace std;

int n,m, s, t;
vector<pair<int,int>> adj[100002];
bool visited[500002];

void dfs(int u, int c)
{
    visited[u] = true;
    for(pair<int,int> p : adj[u])
    {
        int v = p.first;
        if(visited[v] == false && p.second >= c)
            dfs(v, c);
    }
}

bool check(int x)
{
    memset(visited, false, sizeof(visited));
    dfs(s, x);
    return visited[t] == true;
}

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c});
    }
    int lo = 1, hi = 10000, mid, res;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            res = mid;
            lo = mid + 1;
        } else
        {
            hi = mid - 1;
        }
    }
    cout << res;
}
