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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,q;
ll a[SZ], sum[SZ], suf[SZ];

int main()
{
    init();
    cin >> n >> q;
    sum[n+1] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    suf[n+1] = 0;
    for(int i = n; i >= 1; i--)
    {
        sum[i] = sum[i+1] + a[i];
        suf[i] = suf[i+1] + sum[i];
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << suf[l] - suf[r+1] - (r-l+1)*(sum[r+1]) << '\n';
    }
}

