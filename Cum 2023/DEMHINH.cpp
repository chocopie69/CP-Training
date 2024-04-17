#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DEMHINH"

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

ll n,a[LIMIT], res = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i < n && a[i] == a[i+1]) cnt++;
        else
        {
            res += (cnt/4);
            cnt = 1;
        }
    }
    cout << res;
}
