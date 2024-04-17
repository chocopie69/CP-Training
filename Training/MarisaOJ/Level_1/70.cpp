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

int n,q,m,a[SZ], b[SZ];
pii queries[SZ];

int main()
{
    init();
    cin >> n >> q >> m;
    for(int i = 1; i <= q; i++)
    {
        cin >> queries[i].fi >> queries[i].se;
    }
    while(m--)
    {
        int lo,hi;
        cin >> lo >> hi;
        b[lo]++;
        b[hi+1]--;
    }
    for(int i = 1; i <= q; i++)
    {
        b[i] += b[i-1];
        a[queries[i].fi] += b[i];
        a[queries[i].se+1] -= b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        a[i] += a[i-1];
        cout << a[i] << ' ';
    }
}

