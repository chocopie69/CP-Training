#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SUMD"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n,sum[20], p10[20];

void preCompute()
{
    p10[0] = 1;
    for(int i = 1; i <= 16; i++)
    {
        p10[i] = p10[i-1]*10;
    }
    sum[0] = 0;
    sum[1] = 45;
    for(int i = 2; i <= 16; i++)
    {
        sum[i] = sum[i-1]*10 + 45*p10[i-1];
    }
}

ll solve(ll x)
{
    if(x < 10) return x*(x+1)/2;
    int d = 0;
    ll cur = 1;
    while(true)
    {
        if(cur * 10 > x) break;
        cur *= 10LL;
        d++;
    }
    ll p = p10[d], nextx = x % p;
    ll first = x/p;
    return first*sum[d] + (first * (first-1) / 2)* p + first*(nextx+1) + solve(nextx);
    //return d;
}

int main()
{
    init();
    cin >> t;
    preCompute();
    while(t--)
    {
        cin >> n;
        cout << solve(n) << '\n';
    }
}
