#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DELARR"

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

int n, res;
ll a[SZ], sum[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    int j = n;
    res = n;
    for(int i = 1; i <= n; i++)
    {
        if(sum[j] - sum[i-1] < 0) continue;
        while(j > i && a[j] > 0 && sum[j-1] - sum[i-1] >= 0) j--;
        if(sum[j] - sum[i-1] == 0) res = min(res, n - (j-i+1));
    }
    cout << res;
}

/*
6
0 0 0 0 3 4
*/
