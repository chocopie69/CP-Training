#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k;

int sum(int x)
{
    return x*(x+1)/2;
}

int main()
{
    init();
    cin >> n >> k;
    int lo = 0, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(5*sum(mid) + k <= 240)
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    cout << hi;
}
