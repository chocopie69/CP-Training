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

int n,k,a[LIMIT],res;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    a[n+1] = INF;
    int left = 1, right = a[n]-a[1];
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int i = 1, cnt = 0;
        while(i <= n)
        {
            int cur = a[i] + mid*2;
            i = upper_bound(a+1,a+n+2,cur) - a;
            cnt++;
        }
        if(cnt <= k)
        {
            res = mid;
            right = mid-1;
        } else
        {
            left = mid+1;
        }
    }
    cout << res;
}

