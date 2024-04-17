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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[SZ], res = INF;

void lis(int n)
{
    vector<int> b(n+1,INT_MAX);
    b[0]=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res = min(res, n - k );
    }
}

void lds(int n)
{
    vector<int> c(n+2,INT_MIN);
    c[0]=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int lo = 1, hi = n, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(c[mid] <= a[i])
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        c[lo]=a[i];
        res = min(res,n - lo);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    lis(n);
    lds(n);
    cout << res;
}
