#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,d,r,a[LIMIT],b[LIMIT], res;

int main()
{
    init();
    while(cin >> n >> d >> r)
    {
        if(n == 0) break;
        res = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        sort(a+1,a+1+n,greater<int>());
        sort(b+1,b+1+n);
        for(int i = 1; i <= n; i++)
        {
            res += max(a[i]+b[i]-d,0)*r;
        }
        cout << res << '\n';
    }
}

