#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 500+5, SZ2 = 5e5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, xi[4] = {1, 0, -1, 0}, yi[4] = {0, 1, 0, -1}, num[SZ2], low[SZ2], timer = 0, deg[SZ2], bcc = 0;
char a[SZ][SZ];
vector<int> adj[SZ2];
stack<int> st;
ll res, cnt = 0;

int getID(int x, int y)
{
    return m * (x-1) + y;
}

void dfs(int u, int prev)
{
    num[u] = low[u] = ++timer;
    st.push(u);
    for(int v : adj[u])
    {
        if(v == prev) continue;
        if(!num[v])
        {
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[u])
            {
                bcc++;
                deg[n*m + bcc]++;
                //cout << u << " " << n*m+bcc << '\n';
                int k = 0;
                do
                {
                    k = st.top();
                    st.pop();
                    deg[n*m + bcc]++;
                    //cout << n*m+bcc << " " << k << '\n';
                } while(k != v);
            }
        } else
        {
            low[u] = min(low[u], num[v]);
        }
    }
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
            if(a[i][j] == '.') cnt++;
        }
    }
    res = cnt * (cnt-1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] != '.') continue;
            for(int k = 0; k < 4; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.')
                {
                    adj[getID(i,j)].push_back(getID(x,y));
                    adj[getID(x,y)].push_back(getID(i,j));
                    //cout << i << " " << j << " " << getID(i,j) << " - " << x << " " << y << " " << getID(x,y) << '\n';
                }
            }
        }
    }
    for(int u = 1; u <= n*m; u++)
    {
        if(!num[u])
        {
            dfs(u, u);
            //cout << u << " " << res << '\n';
        }
    }
    for(int i = n*m+1; i <= n*m+bcc; i++)
    {
        if(deg[i] < 2) continue;
        res -= 1LL*deg[i]*(deg[i]-1);
    }
    cout << res;
}

