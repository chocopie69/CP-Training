#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "uocso"

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

int a,b, mx = 0, minx, cnt = 0;

int calc(int x)
{
    int res = 0;
    for(int i = 1; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            res++;
            if(i * i != x) res++;
        }
    }
    return res;
}

int main()
{
    init();
    cin >> a >> b;
    for(int x = a; x <= b; x++)
    {
        if(calc(x) > mx)
        {
            mx = calc(x);
            cnt = 1;
            minx = x;
        } else if(calc(x) == mx)
        {
            cnt++;
        }
    }
    cout << minx << " " << mx << " " << cnt;
}
