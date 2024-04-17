#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TRONGCAY"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n,k, a[SZ], b[SZ], m = 0, sum1 = 0, sum2 = 0, res = 0;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i != k)
        {
            m++;
            b[m] = a[i];
        }
    }
    sort(b + 1, b + m + 1);
    for(int i = 2; i < k; i++)
    {
        sum1 += b[i] - b[i-1];
    }
    for(int i = k + 1; i <= m; i++)
    {
        sum2 += b[i] - b[i-1];
    }
    if(k != 1) res += sum1 + min( abs(a[k] - b[1]), abs( a[k] - b[k-1] ) );
    if(k != n) res += sum2 + min( abs(a[k] - b[k]), abs( a[k] - b[m] ) );
    //cout << sum1 << " " << sum2 << " " << res;
    cout << res;
}

/*
5 2
7 7 4 2 6
*/
