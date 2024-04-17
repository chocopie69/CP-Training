#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 3e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t, deg[SZ], a[SZ][SZ], x[SZ], y[SZ], n;
vector<int> adj[SZ];

void reset()
{
    memset(a,0,sizeof(a));
    for(int i = 1; i <= 2048; i++)
    {
        adj[i].clear();
        deg[i] = 0;
    }
}

void dfs(int u)
{
    for(int v : adj[u])
    {
        if(a[u][v] == 1)
        {
            a[u][v] = 2;
            a[v][u] = 0;
            deg[u]--;
            deg[v]--;
            dfs(v);
            break;
        }
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        reset();
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            adj[x[i]].push_back(y[i] + 1024);
            adj[y[i] + 1024].push_back(x[i]);
            a[x[i]][y[i] + 1024] = 1;
            a[y[i] + 1024][x[i]] = 1;
            deg[x[i]]++;
            deg[y[i] + 1024]++;
        }
        bool flag = true;
        while(flag)
        {
            flag = false;
            for(int i = 1; i <= 2048; i++)
            {
                if(deg[i] % 2 == 1)
                {
                    dfs(i);
                    flag = true;
                }
            }
            for(int i = 1; i <= 2048; i++)
            {
                if(deg[i] % 2 == 0 && deg[i] > 0)
                {
                    dfs(i);
                    flag = true;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[x[i]][y[i]+1024] == 2) cout<<'B';
            else cout<<'R';
        }
        cout << '\n';
    }
}
