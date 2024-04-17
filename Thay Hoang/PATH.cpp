#include <bits/stdc++.h>
#define ll long long
#define pii pair<long long, long long>

#define TASKNAME "PATH"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m,n,k;
pii a[LIMIT];
queue<pii> qu;
bool vis[LIMIT];

ll dist(pii x, pii y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

bool check(ll q)
{
    memset(vis,false,sizeof(vis));
    while(!qu.empty())
    {
        qu.pop();
    }
    qu.push({1,1});
    while(!qu.empty())
    {
        pii u = qu.front();
        for(int i = 0; i <= k; i++)
        {
            if(vis[i]) continue;
            pii v = a[i];
            if(dist(u,v) <= q)
            {
                if(v.first == m && v.second == n) return true;
                qu.push(v);
                vis[i] = true;
            }
        }
        qu.pop();
    }
    return false;
}

int main()
{
    init();
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    a[k] = {m,n};
    ll L = 0, R = 2e9;
    while(L <= R)
    {
        ll mid = (L+R)/2;
        if(check(mid))
        {
            R = mid-1;
        } else
        {
            L = mid+1;
        }
    }
    cout << L;
}

