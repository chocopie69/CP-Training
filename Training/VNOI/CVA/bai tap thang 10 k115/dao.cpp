#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
pair<int,int> a[1002];
vector<int> adj[1002];

int dodai(int i, int j)
{
    int x = abs(a[i].first - a[j].first);
    int y = abs(a[i].second - a[j].second);
    return x*x + y*y; /// cong thuc do dai duong cheo theo pitago
}

queue<int> qu;
bool visited[1002];
int truoc[1002];

void bfs()
{
    qu.push(s);
    visited[s] = true;
    truoc[s] = 0;
    while(qu.empty() == false)
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(visited[v] == false)
            {
                truoc[v] = u;
                visited[v] = true;
                qu.push(v);
            }
        }
    }
}

stack<int> ans;

int main()
{
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int w = dodai(i,j);
            if(w < m * m) /// kiem tra tu i di duoc den j hay khong
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bfs();
    if(visited[t] == false)
    {
        cout << -1;
        return 0;
    }
    int u = t;
    while(u != 0) /// truy vet lai duong di
    {
        ans.push(u);
        u = truoc[u];
    }
    cout << ans.size() - 2 << '\n';
    while(ans.empty() == false) /// in ra duong di theo dung thu tu
    {
        int u = ans.top();
        if(u != s && u != t)
        {
            cout << u << " ";
        }
        ans.pop();
    }
}
