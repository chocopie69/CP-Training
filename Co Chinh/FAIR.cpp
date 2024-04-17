#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "FAIR"

using namespace std;

const int SZ = 1e3+5, SZ2 = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m, d[SZ2],a[SZ][SZ], res = INFLL;
bool vis[SZ2];
vector<pll> adj[SZ2];

deque<int> dq;

int getID(int x, int y)
{
    return (x-1)*m+y;
}

pii getID(int x)
{
    return {(x-1)/m + 1, (x % m == 0 && x != 0 ? m : x % m)};
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        adj[0].push_back({getID(i,1),1});
        for(int j = 1; j <= m; j++)
        {
            if(i != n)
                adj[getID(i,j)].push_back({getID(i+1,j), (a[i][j] == a[i+1][j] ? 0 : 1) });
            if(i != 1)
                adj[getID(i,j)].push_back({getID(i-1,j), (a[i][j] == a[i-1][j] ? 0 : 1) });
            if(j != m)
                adj[getID(i,j)].push_back({getID(i,j+1), (a[i][j] == a[i][j+1] ? 0 : 1) });
            if(j != 1)
                adj[getID(i,j)].push_back({getID(i,j-1), (a[i][j] == a[i][j-1] ? 0 : 1) });
        }
    }
    for(int i = 1; i < SZ2; i++)
    {
        d[i] = INFLL;
    }
    d[0] = 0;
    dq.push_front(0);
    memset(vis,false,sizeof(vis));
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if(vis[u]) continue;
        vis[u] = true;
        if(getID(u).se == m)
        {
            //cout << d[u] << " " << getID(u).fi << " " << getID(u).se << " " << u << '\n';
            res = min(res,d[u]);
        }
        for(pll p : adj[u])
        {
            ll v = p.first, w = p.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if(w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
    cout << res;
}


