#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "POWER"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,a[SZ],lcm = 1, res = 1;

ll getLCM(ll x, ll y)
{
    return x*y/__gcd(x,y);
}

vector<ll> num;
int cnt[SZ], maxP = 0;

void phantich(ll x)
{
    memset(cnt,0,sizeof(cnt));
    for(ll i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            while(x % i == 0)
            {
                x /= i;
                cnt[i]++;
            }
            maxP = max(maxP,cnt[i]);
            num.push_back(i);
            res *= i;
        }
    }
    if(x != 1)
    {
        cnt[x]++;
        num.push_back(x);
        res *= x;
    }
}

ll pow2(ll x, ll y)
{
    ll res = 1;
    for(int i = 1; i <= y; i++)
    {
        res *= x;
    }
    return res;
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lcm = getLCM(lcm,a[i]);
    }
    phantich(lcm);
    if(k >= maxP)
    {
        cout << res;
        return 0;
    }
    for(ll x : num)
    {
        if(cnt[x] > k)
        {
            res *= pow2(x,(cnt[x]-1)/k);
        }
    }
    cout << res;
}
