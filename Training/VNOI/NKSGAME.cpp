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

ll n, b[SZ], c[SZ], res = INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    int i = n, j = 1;
    while(i >= 1 && j <= n)
    {
        res = min(res, abs(b[i] + c[j]));
        if(abs(b[i] + c[j]) == 0) break;
        if(b[i] + c[j] > 0) i--;
        else j++;
    }
    cout << res;
}
