#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI2"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, a[SZ], b[SZ];

bool check(int x)
{
    int i = 1, cnt = 0;
    for(int j = 1; j <= m && i <= n/2 ; j++)
    {
        if(a[i] < b[j] && b[j] < a[n - (x - i) ] )
        {
            cnt++;
            i++;
        }
    }
    return cnt >= x;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int lo = 1, hi = min(m,n/2),mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid)) lo = mid+1;
        else hi = mid-1;
    }
    cout << hi;
}
