/// https://marisaoj.com/problem/183

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

const int SZ = 5e3+2, SZ2 = 25000000+2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int k = 10;

int n,a[SZ][SZ], d[SZ2], xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1};
bool vis[SZ2];

int getID(int x, int y)
{
    return (x-1)*n + y;
}

pii getID(int x)
{
    return { (x-1)/n+1, (x-1) % n + 1 };
}

struct Edge
{
    int v, w;
    Edge(int _v = 0, int _w = 0)
    {
        v = _v;
        w = _w;
    }
};

queue<int> qu[11];

int main()
{
    init();
    cin >> n;
    memset(a,-1,sizeof(a));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = int(c) - 48;
        }
    }
    for(int i = 1; i < SZ2; i++)
    {
        d[i] = INF;
    }
    memset(vis,false,sizeof(vis));
    qu[0].push(1);
    d[1] = 0;
    int cnt = 1, pos = 0;
    while(cnt > 0)
    {
        while(qu[pos].empty())
        {
            pos++;
            if(pos >= k)
            {
                pos = 0;
            }
        }
        int u = qu[pos].front();
        qu[pos].pop();
        cnt--;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < 4; i++)
        {
            int x = getID(u).fi + xi[i], y = getID(u).se + yi[i];
            if(x < 1 || x > n || y < 1 || y > n) continue;
            int v = getID(x,y), w = a[x][y];
            if(vis[v]) continue;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                qu[ d[v] % k ].push(v);
                cnt++;
            }
        }
    }
    cout << d[getID(n,n)];
}
