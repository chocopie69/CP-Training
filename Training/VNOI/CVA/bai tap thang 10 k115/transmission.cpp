#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int x,y,p;
};

int n;
Cow a[1002];

int dodai(int i, int j)
{
    int x = abs(a[i].x - a[j].x);
    int y = abs(a[i].y - a[j].y);
    return x*x + y*y; /// cong thuc do dai duong cheo theo pitago
}

vector<int> adj[1002];
bool visited[1002];

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
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,y,p;
        cin >> x >> y >> p;
        a[i].x = x;
        a[i].y = y;
        a[i].p = p;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j && dodai(i,j) <= a[i].p * a[i].p)
            {
                adj[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i);
        int dem = 0;
        for(int j = 1; j <= n; j++)
        {
            if(visited[j]) dem++;
        }
        ans = max(ans, dem);
    }
    cout << ans;
}
