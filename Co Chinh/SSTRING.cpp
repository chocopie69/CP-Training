#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SSTRING"

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

string s;
int n,sum[SZ],cnt[SZ], res1, res2;

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + int(s[i]) - 48;
    }
    int lo = 1, hi = n-1, mid;
    while(lo <= hi)
    {
        bool flag = false;
        mid = (lo + hi) / 2;
        memset(cnt,0,sizeof(cnt));
        for(int i = n - mid + 1; i >= 1; i--)
        {
            int j = i + mid - 1;
            cnt[ sum[j] - sum[i-1] ]++;
        }
        for(int i = mid; i <= n; i++)
        {
            int j = i - mid + 1;
            cnt[sum[i] - sum[j-1]]--;
            if(cnt[sum[i] - sum[j-1]] > 0)
            {
                flag = true;
                res1 = j;
                res2 = i;
                break;
                }
        }
        if(flag)
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    cout << res1 << " " << res2 << " ";
    for(int i = 1; i <= n - hi + 1; i++)
    {
        int j = i + hi - 1;
        if(i == res1) continue;
        if(sum[j] - sum[i-1] == sum[res2] - sum[res1-1])
        {
            cout << i << " " << j;
            break;
        }
    }
}
