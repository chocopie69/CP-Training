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
ll l,r,a[SZ];

int main()
{
    init();
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll res = 0;
    for(int i = 2; i <= n; i++)
    {
        int pos1 = upb(a + 1, a + i, r - a[i]) - a - 1;
        int pos2 = lwb(a + 1, a + i, l - a[i]) - a;
        //cout << a[i] << " " << pos1 << " " << pos2 << '\n';
        res += max(0LL, 1LL*pos1-pos2+1);
    }
    cout << res;
}

