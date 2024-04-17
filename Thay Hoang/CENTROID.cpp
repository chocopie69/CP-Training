#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CENTROID"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, s[SZ], res[SZ];
vector<int> adj[SZ], v;

void dfsSize(int u)
{
    s[u] = 1;
    for(int v : adj[u])
    {
        dfsSize(v);
        s[u] += s[v];
    }
}

void hld(int u)
{
    v.push_back(u);
    if(adj[u].empty())
    {
        int j = 0;
        for(int i = 0; i < v.size(); i++)
        {
            while(j < v.size() && s[v[j]] > s[v[i]] / 2) j++;
            res[v[i]] = v[j-1];
        }
        v.clear();
        return;
    }
    int nextU, maxS = 0;
    for(int v : adj[u])
    {
        if(s[v] > maxS)
        {
            nextU = v;
            maxS = s[v];
        }
    }
    hld(nextU);
    for(int v : adj[u])
    {
        if(v != nextU) hld(v);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfsSize(1);
    hld(1);
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << '\n';
    }
}
