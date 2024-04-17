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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5, OFFSET = 1e5+1;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

string s;
int n, sum = 0;
ll res = 0, x, a[SZ];
map<ll,ll> cnt;

int main()
{
    init();
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cnt[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        res += cnt[sum - x];
        cnt[sum]++;
    }
    cout << res;
}


