#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SHARE"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,a[LIMIT],res[LIMIT], L = INFLL, R = -INFLL, suma = 0;

bool check(ll x)
{
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += min(x,a[i]);
    }
    return sum >= m;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        suma += a[i];
        L = min(L,a[i]);
        R = max(R,a[i]);
    }
    if(suma < m)
    {
        cout << -1;
        return 0;
    }
    while(L <= R)
    {
        ll mid = (L+R)/2;
        if(check(mid))
        {
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        res[i] = min(L,a[i]);
        sum += res[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(sum == m) break;
        if(res[i] == L)
        {
            res[i]--;
            sum--;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}

