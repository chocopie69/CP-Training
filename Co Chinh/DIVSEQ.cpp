#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "DIVSEQ"

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

int n,a[SZ], res = 0, lo = 1, hi = 1;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int i = 1;
    for(int j = 1; j <= n; j++)
    {
        if(i == j || __gcd(a[j],a[j-1]) == min(a[j],a[j-1]))
        {
            if(j-i+1 > res)
            {
                res = j-i+1;
                lo = i;
                hi = j;
            }
        } else
        {
            i = j;
        }
    }
    cout << lo << " " << hi;
}

