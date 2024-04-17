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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int bita, bitb, res = 0;
bool vis[SZ];

queue<pii> qu;

void bfs()
{
    memset(vis,false,sizeof(vis));
    qu.push({bita,0});
    vis[bita] = true;
    while(!qu.empty())
    {
        int mask = qu.front().fi, d = qu.front().se;
        qu.pop();
        if(mask == bitb)
        {
            cout << d;
            return;
        }
        for(int i = 1; i <= 16; i++)
        {
            if(mask >> i & 1)
            {
                if( (i-1) % 4 != 0 && (mask >> (i-1) & 1) == 0 && vis[ mask - (1 << i) + (1 << (i-1) ) ] == false ) /// left
                {
                    qu.push({ mask - (1 << i) + (1 << (i-1) ) , d + 1 } );
                    vis[ mask - (1 << i) + (1 << (i-1) )  ] = true;
                }
                if( i % 4 != 0 && (mask >> (i+1) & 1) == 0 && vis[ mask - (1 << i) + (1 << (i+1) ) ] == false ) /// right
                {
                    qu.push({ mask - (1 << i) + (1 << (i+1) ) , d + 1 } );
                    vis[ mask - (1 << i) + (1 << (i+1) )  ] = true;
                }
                if( i > 4 && (mask >> (i-4) & 1) == 0 && vis[ mask - (1 << i) + (1 << (i-4) ) ] == false ) /// up
                {
                    qu.push({ mask - (1 << i) + (1 << (i-4) ) , d + 1 } );
                    vis[ mask - (1 << i) + (1 << (i-4) )  ] = true;
                }
                if( i <= 12 && (mask >> (i+4) & 1) == 0 && vis[ mask - (1 << i) + (1 << (i+4) ) ] == false ) /// down
                {
                    qu.push({ mask - (1 << i) + (1 << (i+4) ) , d + 1 } );
                    vis[ mask - (1 << i) + (1 << (i+4) )  ] = true;
                }
            }
        }
    }
}

int main()
{
    init();
    for(int i = 1; i <= 16; i++)
    {
        char c;
        cin >> c;
        if(c == '1') bita |= (1 << i);
    }
    for(int i = 1; i <= 16; i++)
    {
        char c;
        cin >> c;
        if(c == '1') bitb |= (1 << i);
    }
    bfs();
}

/*
1111
0000
1111
1111

1001
1100
1111
1111
*/
