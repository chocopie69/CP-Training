#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> adj[500002];
bool visited[500002];

void dfs(int u, int i)
{
    visited[u] = true;
    for(pair<int,int> p : adj[u])
    {
        int v = p.first;
        if(visited[v] == false && p.second <= i)
            dfs(v, i);
    }
}

bool check(int x)
{
    memset(visited, false, sizeof(visited));
    dfs(1, x);
    return visited[n] == true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back({ v, i });
    }
    int lo = 1, hi = m, mid, res = -1;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            res = mid;
            hi = mid - 1;
        } else
        {
            lo = mid + 1;
        }
    }
    cout << res;
}

/*
4 4
1 2
3 4
4 1
3 2
*/
