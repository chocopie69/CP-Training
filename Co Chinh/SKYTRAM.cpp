#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "SKYTRAM"

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

ll n,s,a[SZ], res = 0;

int main()
{
    init();
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int i = 0, j = n-1;
    while(i < j)
    {
        res++;
        if(a[i] + a[j] <= s)
        {
            i++;
        }
        j--;
    }
    if(i == j) res++;
    cout << res;
}

