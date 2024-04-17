#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DLT"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll a,b, res;

ll power(ll a, ll b)
{
    if(b == 0) return 1LL;
    ll cur = power(a,b/2);
    if(b % 2 == 0) return ((cur % MOD) * (cur % MOD)) % MOD;
    return ( ( ((cur % MOD) * (cur % MOD)) % MOD ) * (a % MOD)) % MOD;
}

bool vis[102][102];

namespace sub12
{

    ll p[1010][1010];

    void preCalc()
    {
        memset(p,-1,sizeof(p));
        for(ll i = 1; i <= a; i++)
        {
            ll x = i;
            for(ll j = 1; j <= b; j++)
            {
                if(x > a) break;
                p[i][j] = x;
                x *= i;
            }
        }
    }

    void solve()
    {
        preCalc();
        res = a*b - (b-1);
        memset(vis,false,sizeof(vis));
        for(ll i = 2; i <= a; i++)
        {
            for(ll j = 1; j <= b; j++)
            {
                for(ll x = 1; x * 2 <= j; x++)
                {
                    if(j % x == 0)
                    {
                        ll k = j/x;
                        if(x != 1 && p[i][x] != -1 && !vis[ p[i][x] ][k])
                        {
                            //vis[ p[i][x] ][k] = true;
                            res--;
                            //cout << i << " " << x << " " << k << " " << p[i][x] << '\n';
                        }
                        if(k != x && p[i][k] != -1 && !vis[ p[i][k] ][x])
                        {
                            //vis[ p[i][k] ][x] = true;
                            res--;
                            //cout << i << " " << k << " " << x << " " << p[i][k] << '\n';
                        }
                    }
                }
            }
        }
        cout << res;
    }
}

namespace sub3
{
    map<ll,ll> mp;
    void solve()
    {
        for(ll i = 2; i <= a; i++)
        {
            for(ll j = 1; j <= b; j++)
            {
                mp[power(i,j)] = 727;
            }
        }
        cout << mp.size() + 1;
    }
}

int main()
{
    init();
    cin >> a >> b;
    if(a <= 605)
        sub12::solve();
    else
        sub3::solve();
}
