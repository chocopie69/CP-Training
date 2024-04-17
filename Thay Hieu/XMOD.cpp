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

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[SZ],b[SZ],xmax[SZ],xmin[SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i < SZ; i++)
    {
        xmin[i] = INF;
        xmax[i] = 0;
    }
    xmin[0] = 0;
    xmax[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(xmin[a[i]] == INF)
        {
            for(int j = a[i]; j < SZ; j += a[i])
            {
                xmin[j] = 0;
                xmax[j-1] = max(xmax[j-1],a[i] - 1);
            }
        }
    }
    for(int i = 1; i < SZ; i++)
    {
        xmin[i] = min(xmin[i-1] + 1, xmin[i]);
    }
    for(int i = SZ-2; i >= 1; i--)
    {
        xmax[i] = max(xmax[i], xmax[i+1] - 1);
    }
    for(int i = 1; i <= m; i++)
    {
        cout << xmin[b[i]] << " " << xmax[b[i]] << '\n';
    }
}
