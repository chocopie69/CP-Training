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

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;

ll minPrime[SZ];

void sieve()
{
    for (int i = 2; i * i < SZ; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j < SZ; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = 1LL*i;
                }
            }
        }
    }
    for (int i = 2; i < SZ; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = 1LL*i;
        }
    }
}

bool vis[SZ];
vector<ll> v;

ll cnt[2][SZ];

void phantich(ll x, int i)
{
    while(x > 1)
    {
        ll cur = minPrime[x];
        if(!vis[cur])
        {
            vis[cur] = true;
            v.push_back(cur);
        }
        int d = 0;
        while(cur == minPrime[x] && x > 1)
        {
            x /= cur;
            d++;
        }
        cnt[i][cur] += d;
    }
}

ll n,k, res = 1;

void reset()
{
    while(!v.empty())
    {
        cnt[0][v.back()] = 0;
        cnt[1][v.back()] = 0;
        vis[v.back()] = false;
        v.pop_back();
    }
    res = 1;
}

int main()
{
    init();
    sieve();
    cin >> t;
    while(t--)
    {
        reset();
        cin >> n >> k;
        phantich(n,0);
        phantich(k,1);
        for(ll x : v)
        {
            //cout << cnt[0][x] << " " << cnt[1][x] << " " << x << '\n';
            int mx = max(cnt[0][x], cnt[1][x]);
            int d = mx + (mx % 2 == 1) - cnt[1][x];
            for(int i = 1; i <= d; i++)
            {
                res *= x;
            }
        }
        cout << res << '\n';
    }
}
