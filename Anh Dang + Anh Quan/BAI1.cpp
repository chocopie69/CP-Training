#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI1"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int a,b,c, res = 0;

int main()
{
    init();
    cin >> a >> b >> c;
    for(int x = 1; x <= c; x++)
    {
        if( (c - a*x) % b != 0 ) continue;
        int y = (c - a*x) / b;
        if(y > 0 && __gcd(x,y) == 1) res++;
    }
    cout << res;
}
