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

const int SZ = 1e6+5, SZ2 = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    int u,v;
    ll w;
    Edge(int _u = 0, int _v = 0, ll _w = 0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

ll n,m,k,u,v,w, c[SZ2][SZ2], s[SZ], cnt = 0, id[SZ];
vector<Edge> edges;
vector<int> vertices;
bool inTree[SZ];

namespace sub1
{
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                c[i][j] = INFLL;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            c[u][v] = w;
            c[v][u] = w;
        }
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(c[i][j] > c[i][k] + c[k][j]) c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                cnt++;
                s[cnt] = c[i][j];
                //cout << i << " " << j << " " << c[i][j] << '\n';
            }
        }
        sort(s+1,s+cnt+1);
        cout << s[k];
    }
}

namespace sub2
{
    bool cmp(Edge x, Edge y)
    {
        return x.w < y.w;
    }

    int u,v;
    ll w;

    void makeTree()
    {
        sort(all(edges),cmp);
        memset(inTree,false,sizeof(inTree));
        memset(id,-1,sizeof(id));
        for(int i = 1; i <= 605; i++)
        {
            for(int j = 1; j <= 605; j++)
            {
                c[i][j] = INFLL;
            }
        }
        n = 0;
        for(int i = 0; i < k && i < edges.size(); i++)
        {
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
            if(id[u] == -1)
            {
                n++;
                id[u] = n;
                u = n;
                vertices.push_back(u);
            } else u = id[u];
            if(id[v] == -1)
            {
                n++;
                id[v] = n;
                v = n;
                vertices.push_back(v);
            } else v = id[v];
            c[u][v] = w;
            c[v][u] = w;
        }
    }

    void solve()
    {
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v >> w;
            edges.push_back({u,v,w});
        }
        makeTree();
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(c[i][j] > c[i][k] + c[k][j]) c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                cnt++;
                s[cnt] = c[i][j];
                //cout << u << " " << v << " " << c[u][v] << '\n';
            }
        }
        sort(s+1,s+cnt+1);
        cout << s[k];
    }
}

int main()
{
    init();
    cin >> n >> m >> k;
    if(n <= 300)
        sub1::solve();
    else
        sub2::solve();
}
