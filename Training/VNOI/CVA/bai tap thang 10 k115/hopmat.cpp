#include <bits/stdc++.h>
using namespace std;

int k,n,m, a[102], cnt[1002];
vector<int> adj[1002];

bool visited[1002];

void dfs(int u)
{
    cnt[u]++;
    visited[u] = true;
    for(int v : adj[u])
    {
        if(visited[v] == false) dfs(v);
    }
}

int main()
{
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= k; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(a[i]);
    }
    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == k)
            dem++;
    }
    cout << dem;
}
