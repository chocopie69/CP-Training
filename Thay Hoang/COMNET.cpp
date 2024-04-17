#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 5*1e5+5;
int n,m,u,v;
vector<int> adj[LIMIT];
queue<int> qu;
bool pathExist[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COMNET.INP","r",stdin);
    freopen("COMNET.OUT","w",stdout);
    memset(pathExist,false,sizeof(pathExist));
}

void bfs()
{
    qu.push(v);
    pathExist[v] = true;
    while(!qu.empty())
    {
        int x = qu.front();
        for(int cur : adj[x])
        {
            if(!pathExist[cur])
            {
                qu.push(cur);
                pathExist[cur] = true;
            }
        }
        qu.pop();
    }
}

int main()
{
    init();
    cin >> n >> m;
    pathExist[1] = true;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        if(pathExist[u] && !pathExist[v])
        {
            bfs();
            if(pathExist[n])
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
}

/*
4 5
1 2
3 4
4 1
2 3
3 2
*/
