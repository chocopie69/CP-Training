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

const int SZ = 500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m;
ll a[SZ][SZ], sum[SZ][SZ], cnt[10], res = 0;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }
    }
    for(int lo = 1; lo <= m; lo++)
    {
        for(int hi = lo; hi <= m; hi++)
        {
            cnt[0] = 1;
            ll s = 0;
            for(int i = 1; i <= n; i++)
            {
                s += sum[i][hi] - sum[i][lo-1];
                res += cnt[s % 9];
                cnt[s % 9]++;
            }
            s = 0;
            for(int i = 1; i <= n; i++)
            {
                s += sum[i][hi] - sum[i][lo-1];
                cnt[s % 9]--;
            }
        }
    }
    cout << res;
}

