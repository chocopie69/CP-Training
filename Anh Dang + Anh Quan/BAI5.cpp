#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI5"

using namespace std;

const int SZ = 3e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, res[SZ][SZ], color[SZ], d[SZ];
bitset<305> a[SZ], emp;

vector<int> adj[SZ];

void createGraph()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j && (a[i] & a[j]) != emp)
            {
                adj[i].push_back(j);
            }
        }
    }
}

deque<int> dq;

void calcDist(int s)
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    dq.push_back(s);
    d[s] = 0;
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        for(int v : adj[u])
        {
            int w = color[v];
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if(w == 1) dq.push_back(v);
                else dq.push_front(v);
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            a[i].set(x);
        }
    }
    createGraph();
    for(int u = 1; u <= n; u++)
    {
        for(int v = 1; v <= n; v++)
        {
            res[u][v] = (u == v ? 0 : INF);
        }
    }
    for(int lang = 1; lang <= m; lang++)
    {
        int s = -1, cnt = 0;
        for(int u = 1; u <= n; u++)
        {
            if(a[u].test(lang))
            {
                cnt++;
                color[u] = 0;
                s = u;
            }
            else
            {
                color[u] = 1;
            }
        }
        if(s == -1)
        {
            continue;
        }
        calcDist(s);
        for(int u = 1; u <= n; u++)
        {
            if(!a[u].test(lang)) continue;
            for(int v = 1; v <= n; v++)
            {
                if(u == v) continue;
                res[u][v] = min(res[u][v], d[v] + cnt);
            }
        }
    }
    for(int u = 1; u <= n; u++)
    {
        for(int v = 1; v <= n; v++)
        {
            cout << res[u][v] << " ";
        }
        cout << '\n';
    }
}
