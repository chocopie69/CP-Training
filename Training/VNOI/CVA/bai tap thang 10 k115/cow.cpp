#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[10000];
bool visited[1000];

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(visited[v] == false) dfs(v);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    bool timthay = false;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            cout << i << '\n';
            timthay = true;
        }
    }
    if(timthay == false) cout << 0;
}
