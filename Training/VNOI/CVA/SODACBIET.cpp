#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SODACBIET"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ull pow10[SZ], a, b, k;

int main()
{
    init();
    pow10[0] = 1;
    for(int i = 1; i <= 18; i++)
    {
        pow10[i] = pow10[i-1] * 10;
    }
    cin >> a >> b >> k;
    for(int x = 2; x <= 18; x++)
    {
        ll cur = a * pow10[x] + b;
        if(cur % (k - 10) == 0)
        {
            cout << cur / (k - 10);
            return 0;
        }
    }
}
