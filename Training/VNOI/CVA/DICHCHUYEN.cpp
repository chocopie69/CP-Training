#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DICHCHUYEN"

using namespace std;

const int SZ = 2e6+5, SZ2 = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;

int getID(int x, int y)
{
    return m*(x-1) + y;
}

pii getID(int x)
{
    return { (x-1) / m + 1, (x-1) % m + 1 };
}

int sx, sy, tx, ty, a[SZ2][SZ2], xi[4] = {1, 0, -1, 0}, yi[4] = {0, 1, 0, -1}, id[SZ], cur;
vector<int> nen;

bool valid(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 0;
}

struct Edge
{
    int v, w;
    Edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj[SZ];

int d[SZ];
deque<int> dq;
bool vis[SZ], vis2[SZ];

void bfs01(int s)
{
    for(int i = 1; i < SZ; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    dq.push_front(s);
    vis[s] = true;
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if(u == getID(tx,ty)) break;
        for(Edge e : adj[u])
        {
            int v = e.v, w = e.w;
            if(vis[v]) continue;
            if(w == 0)
            {
                if(vis[a[getID(v).fi][getID(v).se]]) continue;
                vis[a[getID(v).fi][getID(v).se]] = true;
            }
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if(w == 1) dq.push_back(v);
                else dq.push_front(v);
                vis[v] = true;
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m >> sx >> sy >> tx >> ty;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0) continue;
            nen.push_back(a[i][j]);
        }
    }
    sort(all(nen));
    cur = n*m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 0) continue;
            int pos = lower_bound(all(nen), a[i][j]) - nen.begin() + 1;
            a[i][j] = pos;
            if(id[pos] == 0)
            {
                cur++;
                id[pos] = cur;
            }
            int p = getID(i,j);
            adj[p].push_back({id[pos], 0});
            adj[id[pos]].push_back({p, 1});
            for(int k = 0; k < 4; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(valid(x,y))
                {
                    adj[p].push_back({getID(x,y),1});
                    //adj[getID(x,y)].push_back({get})
                }
            }
        }
    }
    bfs01(getID(sx,sy));
    cout << d[getID(tx,ty)];
}

/*
5 4
1 1 5 4
1 2 3 4
5 0 0 6
7 0 8 9
0 0 10 0
11 12 13 14
*/
