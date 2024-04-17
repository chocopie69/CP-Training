#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ASSIGN"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int m, n, p;
vector<int> adj[SZ]; /// adj[i] : danh sach cac viec ma tho i co the am
int match[SZ]; /// match[j], tho duoc giao lam viec j, = 0 neu chua duoc giao
vector<int> s; /// danh sach cac tho chua duoc giao viec
int vis[SZ], timer = 0;

bool dfs(int x)
{
    for(int y : adj[x])
    {
        if(vis[y] == timer) continue;
        vis[y] = timer;
        if(match[y] == 0 || dfs(match[y]))
        {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    init();
    cin >> m >> n >> p;
    for(int i = 1; i <= p; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(match, 0, sizeof(match));
    for(int i = 1; i <= m; i++) s.push_back(i);
    for(int i = s.size() - 1; i >= 0; i--)
    {
        ++timer;
        if(dfs(s[i]))
        {
            s[i] = s.back();
            s.pop_back();
        }
    }
    cout << m - s.size() << '\n';
    for(int i = 1; i <= n; i++)
    {
        cout << match[i] << " ";
    }
}
