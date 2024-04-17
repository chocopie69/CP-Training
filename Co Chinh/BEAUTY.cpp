#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BEAUTY"

using namespace std;

const int SZ = 1e6+5, OFFSET = 2e5+3;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, a[SZ], res = 0;
set<int> s;
bool exist[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        bool flag = false;
        for(int j = 1; j < i; j++)
        {
            if(exist[ a[i] - a[j] + OFFSET ]) flag = true;
        }
        if(flag) res++;
        for(int j = 1; j <= i; j++)
        {
            exist[ a[i] + a[j] + OFFSET ] = true;
        }
    }
    cout << res;
}
