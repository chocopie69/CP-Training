#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n,cnt[LIMIT],sum1[LIMIT],sum2[LIMIT],res = 0;
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        memset(cnt,0,sizeof(cnt));
        s = ' ' + s;
        sum1[0] = 0;
        sum2[n+1] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt[int(s[i])] == 0)
                sum1[i] = sum1[i-1] + 1, cnt[int(s[i])] = 1;
            else sum1[i] = sum1[i-1];
        }
        memset(cnt,0,sizeof(cnt));
        for(int i = n; i >= 1; i--)
        {
            if(cnt[int(s[i])] == 0)
                sum2[i] = sum2[i+1] + 1, cnt[int(s[i])] = 1;
            else sum2[i] = sum2[i+1];
        }
        res = sum1[n];
        for(int i = 1; i <= n; i++)
        {
            res = max(res,sum1[i] + sum2[i+1]);
        }
        cout << res << '\n';
    }
}


