#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "TUNNEL"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,x,y;
vector<int> adj[SZ];

int main()
{
    init();
    cin >> n >> m >> x >> y;
    for(int i = 0; i < m; i++)
    {
        int u,v,h,d;
        cin >> u >> v >> h >> d;
        adj[u]
    }
}
