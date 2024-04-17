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

const int SZ = 1e7+1e6;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int m, q, g[SZ+SZ+5], res[SZ+SZ+5];

int main()
{
    init();
    for(int i = 1; i < SZ; i++)
    {
        g[i] = INF;
        res[i] = INF;
    }
    cin >> m >> q;
    int id = 0;
    while(m--)
    {
        int x;
        cin >> x;
        for(int i = x-1; i < SZ+SZ; i += x)
        {
            g[i] = min(g[i],i-x+1);
        }
    }
    for(int i = SZ-2; i >= 0; i--)
    {
        g[i] = min(g[i],g[i+1]);
    }
    for(int i = 1; i < SZ; i++)
    {
        if(g[i] >= INF) res[i] = INF;
        else res[i] = res[g[i]] + 1;
    }
    while(q--)
    {
        int x;
        cin >> x;
        if(res[x] >= INF) cout << "oo\n";
        else cout << res[x] << '\n';
    }
}
