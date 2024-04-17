#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e3+5;
int u,v,n,m;
vector<int> graph[LIMIT];

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v;
        if(u == v) continue;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        for(int x : graph[i])
        {
            cout << x << " ";
        }
        cout << 0 << '\n';
    }
}
