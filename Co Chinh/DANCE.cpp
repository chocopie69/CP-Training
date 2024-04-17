#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DANCE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n,k, type[SZ], h[SZ], a[SZ], b[SZ], m = 0, p = 0;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> type[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if(type[i] == 1)
        {
            m++;
            a[m] = h[i];
        } else
        {
            p++;
            b[p] = h[i];
        }
    }
    sort(a + 1, a + m + 1);
    sort(b + 1, b + p + 1);
    int j = 1, res = 0;
    for(int i = 1; i <= m; i++)
    {
        while(j <= p && a[i] > b[j]) j++;
        if(j > p) break;
        if(b[j] <= a[i]+k)
        {
            res++;
            j++;
        }
    }
    cout << res;
}
