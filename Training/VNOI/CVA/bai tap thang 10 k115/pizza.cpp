#include <bits/stdc++.h>
using namespace std;

int n,m,q, a[100002], b[100002], cnt = 0, mx;
vector<int> adj[100002];
bool visited[100002];
long double res[100002];

stack<int> st; /// Danh sach cac nguoi an cung 1 chiec banh

void dfs(int u)
{
    visited[u] = true;
    st.push(u);
    mx = max(mx, b[u]);
    for(int v : adj[u])
    {
        if(visited[v] == false)
            dfs(v);
    }
}

int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int x,k;
            cin >> x >> k;
            b[x] = a[k];
        } else
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            cnt++;
            mx = 0;
            dfs(i);
            int songuoi = st.size();
            while(st.empty() == false)
            {
                res[st.top()] = (long double) mx / songuoi;
                st.pop();
            }
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++)
    {
        cout << fixed << setprecision(8) << res[i] << '\n';
    }
}
