#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MKPALIND"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n, a[SZ], res =0;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll i = 1, j = n;
    while(i < j)
    {
        if(a[i] == a[j])
        {
            i++;
            j--;
            continue;
        }
        if(a[i] < a[j])
        {
            a[i+1] += a[i];
            i++;
            res++;
        } else
        {
            a[j-1] += a[j];
            j--;
            res++;
        }
    }
    cout << res;
}
