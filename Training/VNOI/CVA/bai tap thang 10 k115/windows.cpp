#include <bits/stdc++.h>
using namespace std;

struct Window
{
    int u,v,x,y;
};

int n;
Window a[10002];
bool deleted[10002], visited[10002];
vector<int> adj[10002], res;

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(visited[v] == false) dfs(v);
    }
    res.push_back(u);
}

int main()
{
    ///freopen("windows.inp","r",stdin);
    ///freopen("windows.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].x >> a[i].y;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            int u1 = a[i].u, u2 = a[i].y;
            if(a[j].u <= u1 && a[j].v <= u2 && a[j].x >= u1 && a[j].y >= u2)
            {
                adj[i].push_back(j);
            }
        }
    }
    dfs(1);
    cout << res.size() << '\n';
    for(int x : res)
    {
        cout << x << " ";
    }
}
