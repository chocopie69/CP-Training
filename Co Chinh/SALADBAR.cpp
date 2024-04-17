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

int n, a[SZ], sum[SZ];

int stMax[22][SZ],stMin[22][SZ];

void rmq()
{
    for (int i = 1; i <= n; ++i)
    {
        stMax[0][i] = sum[i];
        stMin[0][i] = sum[i];
    }
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            stMax[j][i] = max(stMax[j - 1][i], stMax[j - 1][i + (1 << (j - 1))]);
            stMin[j][i] = min(stMin[j - 1][i], stMin[j - 1][i + (1 << (j - 1))]);
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
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char c
        cin >> c;
        a[i] == (c == 'p' ? 1 : -1);
        sum[i] = sum[i-1] + a[i];
    }
}
