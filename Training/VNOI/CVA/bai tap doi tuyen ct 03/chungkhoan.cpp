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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int LG = 18;

int n,p,a[SZ], stMax[20][SZ], stMin[20][SZ], res = 1;

void build()
{
    for(int i = 1; i <= n; i++)
    {
        stMax[0][i] = a[i];
        stMin[0][i] = a[i];
    }
    for(int j = 1; j <= LG; j++)
    {
        for(int i = 1; i + (1 << j) < n; i++)
        {
            stMax[j][i] = max(stMax[j-1][i], stMax[j-1][i + (1 << (j-1)) ] );
            stMin[j][i] = min(stMin[j-1][i], stMin[j-1][i + (1 << (j-1)) ] );
        }
    }
}

int getMax(int lo, int hi)
{
    int k = __lg(hi - lo + 1);
    return max(stMax[k][lo], stMax[k][hi - (1 << k) + 1]);
}

int getMin(int lo, int hi)
{
    int k = __lg(hi - lo + 1);
    return min(stMin[k][lo], stMin[k][hi - (1 << k) + 1]);
}

int main()
{
    init();
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build();
    int lo = 1;
    for(int hi = 2; hi <= n; hi++)
    {
        while(lo < hi-1 && getMax(lo,hi) - getMin(lo,hi) > p) lo++;
        if(getMax(lo,hi) - getMin(lo,hi) <= p) res = max(res, hi - lo + 1);
    }
    cout << res;
}
