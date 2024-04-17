#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 4e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n,a,b,d[SZ],f[SZ];

void sang()
{
    for(int i = 1; i*i < SZ; i++)
    {
        for(int j = i*i; j < SZ; j += i)
        {
            d[j] += (j == i*i ? 1 : 2);
        }
    }
    for(int i = 2; i < SZ; i++)
    {
        f[i] = 1;
    }
    for(int i = 2; i < SZ; i++)
    {
        if(f[i] == 1) for(int j = i; j < SZ; j += i)
        {
            f[j] *= i;
        }
    }
}

namespace sub1
{
    void solve()
    {
        int res = 0;
        for(int i = 2; i <= n; i++)
        {
            if(f[i] * i <= n && a <= d[i] && d[i] <= b)
            {
                res++;
                //cout << i << " " << f[i] << " " << d[i] << '\n';
            }
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n >> a >> b;
    sang();
    if(n <= 5e6)
    {
        sub1::solve();
    }
}

