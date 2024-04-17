#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "Thamhiem"

using namespace std;

const int SZ = 6e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, a[SZ],b[SZ], res = 1;
vector<int> adj[SZ];

void dfs(int u, int prev)
{
    //res = max(res, cnt);
    for(int v : adj[u])
    {
        if(v == prev) continue;
        //dfs(v,u,cnt + (a[v] > mx), (a[v] > mx ? a[v] : mx) ) ;
        int pos = lower_bound(b+1,b+n+1,a[v])- b ;
        b[pos] = a[v];
        res = max(res,pos);
        cout << v << " " << a[v] << " " << pos << '\n';
        dfs(v,u);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int s = 1; s <= 1; s++)
    {
        fill(b+1,b+n+1,INF);
        b[0] = -INF;
        b[1] = a[s];
        dfs(s,s);
    }
    cout << res;
}

/*
6
1 2 3 4 5 1
1 2
2 3
3 4
3 5
3 6
*/
