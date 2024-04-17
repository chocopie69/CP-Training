#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "CIRCUIT"

using namespace std;

const int SZ = 1e3+5, SZ2 = 1e6;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct DSU
{
    ll par[SZ2], s[SZ2];

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
        }
    }

    ll get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(s[u] > s[v]) swap(u,v);
        par[v] = u;
        s[v] += s[u];
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

struct Edge
{
    int u, v, w;

    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

int n,m,a[SZ][SZ],b[SZ2], u, v, k = 0, sumV = 0;
vector<Edge> res;

int getID(int x, int y)
{
    return (y-1)*n+x;
}

pii getID(int x)
{
    //return {(x-1)/n + 1, (x % n == 0 ? n : x % n)};
    return { (x % n == 0 ? n : x % n),  (x-1)/n + 1};
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
    dsu.init(n*m+5);
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            b[(j-1)*n + i] = a[i][j];
            if(a[i][j] == 1 || a[i][j] == 3)
            {
                u = getID(i,j);
                v = getID(i+1,j);
                if(!dsu.joined(u,v))
                {
                    dsu.join(u,v);
                }
            }
            if(a[i][j] == 2 || a[i][j] == 3)
            {
                u = getID(i,j);
                v = getID(i,j+1);
                if(!dsu.joined(u,v))
                {
                    dsu.join(u,v);
                }
            }
        }
    }
    for(int i = 1; i <= n*m; i++)
    {
        if(getID(i).first == n) continue;
        if(!dsu.joined(i,i+1))
        {
            dsu.join(i,i+1);
            k++;
            sumV++;
            res.push_back({getID(i).first, getID(i).second, 1});
        }
    }
    for(int i = 1; i <= n*m; i++)
    {
        if(getID(i).second == m) continue;
        if(!dsu.joined(i,i+n))
        {
            dsu.join(i,i+n);
            k++;
            sumV += 2;
            res.push_back({getID(i).first, getID(i).second, 2});
        }
    }
    cout << k << " " << sumV << '\n';
    for(Edge e : res)
    {
        cout << e.u << " " << e.v << " " << e.w << '\n';
    }
}

