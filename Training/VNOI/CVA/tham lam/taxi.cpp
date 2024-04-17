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

int n,a[LIMIT],cnt[LIMIT], res = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    res = cnt[4] + min(cnt[3],cnt[1]) + cnt[2]/2;
    if(cnt[3] >= cnt[1])
    {
        res += (cnt[3] - cnt[1] + (cnt[2] % 2 == 1));
    }
    else
    {
        if(cnt[2] % 2 == 0)
        {
            res += (cnt[1]-cnt[3]-1)/4+1;
        } else
        {
            if(cnt[1] - cnt[3] <= 2) res++;
            else
            {
                res += 1 + (cnt[1]-cnt[3]-3)/4+1;
            }
        }
    }
    cout << res;
}
