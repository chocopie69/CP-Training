#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SWAPER"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, a[SZ], res;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++)
    {
        a[i] = i;
    }
    res = n;
    while(m--)
    {
        int i,j;
        cin >> i >> j;
        if(i > j) swap(i,j);
        if(j > n && i <= n)
        {
            if(a[i] <= n) res--;
            if(a[j] <= n) res++;
        }
        swap(a[i], a[j]);
        cout << res << '\n';
    }
}
