#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LEGOSHOW"

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

ll n,k,a[SZ], lo[SZ], hi[SZ], j, res = 1, maxLeft = 0, pos1, pos2;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    lo[1] = 1;
    j = 1;
    for(int i = 2; i <= n; i++)
    {
        while(abs(a[i] - a[j]) > k && j < i) j++;
        lo[i] = j;
    }
    hi[n] = n;
    j = n;
    for(int i = n-1; i >= 1; i--)
    {
        while(abs(a[i] - a[j]) > k && j > i) j--;
        hi[i] = j;
    }
    for(int i = 1; i < n; i++)
    {
        maxLeft = max(maxLeft,i-lo[i]+1);
        res = max(res, maxLeft + (hi[i+1] - i));
    }
    cout << res;
}
