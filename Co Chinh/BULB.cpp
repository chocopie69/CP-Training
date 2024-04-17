#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
long double length,a[LIMIT];

int main()
{
    init();
    cin >> n >> length;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long double res = max(a[1],length-a[n]);
    for(int i = 2; i <= n; i++)
    {
        res = max(res, (a[i]-a[i-1]) / 2);
    }
    cout << fixed << setprecision(6) << res;
}
