#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI4"

using namespace std;

const int SZ = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

map< pii, vector<pii> > adj;
string s;

map< pii, int> d;
map< pii, bool> vis;
queue<pii> qu;

void bfs(int tx, int ty)
{
    qu.push({0,0});
    d[ {0,0} ] = 0;
    vis[ {0,0} ] = true;
    while(!qu.empty())
    {
        pii u = qu.front();
        qu.pop();
        int x = u.fi, y = u.se;
        for(pii v : adj[ {x,y} ])
        {
            int nx = v.fi, ny = v.se;
            if(vis[ {nx,ny} ]) continue;
            qu.push({nx,ny});
            d[ {nx,ny} ] = d[ {x,y} ] + 1;
            vis[ {nx,ny} ] = true;
        }
    }
    cout << d[ {tx,ty} ];
}

int main()
{
    init();
    int x = 0, y = 0;
    cin >> s;
    for(char c : s)
    {
        int nx = x, ny = y;
        if(c == 'D') nx++;
        else if(c == 'T') nx--;
        else if(c == 'B') ny++;
        else ny--;
        adj[ {nx,ny} ].push_back({x,y});
        adj[ {x,y} ].push_back({nx,ny});
        x = nx;
        y = ny;
    }
    bfs(x,y);
}

