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

ll n,m,c, d[SZ], trace[SZ];
queue<ll> qu;
bool vis[SZ];

ll minPrime[SZ];

void preCompute()
{
    for (int i = 2; i * i < SZ; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j < SZ; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < SZ; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

stack<int> res;

int main()
{
    init();
    preCompute();
    cin >> n >> m >> c;
    qu.push(n);
    memset(d,-1,sizeof(d));
    d[n] = 0;
    trace[n] = -1;
    vis[n] = true;
    while(!qu.empty())
    {
        ll x = qu.front();
        qu.pop();
        ll y = x;
        while(y != 1)
        {
            ll cur = minPrime[y];
            while(cur == minPrime[y])
            {
                y /= cur;
            }
            if(x / cur <= c && vis[x/cur] == false)
            {
                qu.push(x / cur);
                vis[x / cur] = true;
                trace[x / cur] = x;
                d[x / cur] = d[x] + 1;
            }
        }
        if(x * x <= c && vis[x * x] == false)
        {
            qu.push(x * x);
            vis[x * x] = true;
            trace[x * x] = x;
            d[x * x] = d[x] + 1;
        }
    }
    if(d[m] == -1)
    {
        cout << "Impossible";
    } else
    {
        int cur = m;
        while(trace[cur] != -1)
        {
            //cout << cur << " " << trace[cur] << '\n';
            if(trace[cur] > cur)
            {
                res.push(trace[cur] / cur);
                cur = trace[cur];
            } else
            {
                res.push(0);
                cur = trace[cur];
            }
        }
        cout << res.size() << '\n';
        while(!res.empty())
        {
            cout << res.top() << " ";
            res.pop();
        }
    }
}
