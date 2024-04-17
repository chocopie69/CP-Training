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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n;
ll a[SZ], pSum1[SZ], pSum2[SZ], sSum1[SZ], sSum2[SZ];

ll query1(int lo, int hi)
{
    return sSum2[lo] - sSum2[hi+1] - (hi-lo+1)*(sSum1[hi+1]);
}

ll query2(int lo, int hi)
{
    return pSum2[hi] - pSum2[lo-1] - (hi-lo+1)*pSum1[lo-1];
}
ll res = INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n+i] = a[i];
    }
    for(int i = 1; i <= 2*n; i++)
    {
        pSum1[i] = pSum1[i-1] + a[i];
        pSum2[i] = pSum2[i-1] + pSum1[i];
    }
    for(int i = 2*n; i >= 1; i--)
    {
        sSum1[i] = sSum1[i+1] + a[i];
        sSum2[i] = sSum2[i+1] + sSum1[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int j = i + n/2, k = i+n-1;
        res = min(res, query1(i+1, j) + query2(j+1, k));
        //cout << i+1 << " " << j << " " << query1(i+1,j) << " - " << j+1 << " " << k << " " << query2(j+1,k) << '\n';
    }
    cout << res;
}

