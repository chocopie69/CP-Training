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

int t;
ll n,a[LIMIT], sum[LIMIT];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(sum[i-1] == sum[n]-sum[i])
            {
                flag = true;
                cout << i << '\n';
                break;
            }
        }
        if(!flag) cout << -1 << '\n';
    }
}
