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

ll n, a[LIMIT], res = 0, sum = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] < sum)
        {
            res += (sum-a[i]);
            a[i+1] -= (sum-a[i]);
            a[i] = sum;
        }
        else
        {
            res += (a[i]-sum);
            a[i+1] += (a[i]-sum);
            a[i] = sum;
        }
    }
    cout << res;
}

