#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SEGMENTS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ],sum[SZ], res = 1;

int main()
{
    init();
    cin >> n;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(sum[n] % sum[i] == 0)
        {
            int j = i+1;
            bool check = true;
            ll cnt = 1;
            while(j <= n)
            {
                int pos = lower_bound(sum+j,sum+n+1,sum[j-1] + sum[i]) - sum;
//                if(i == 3)
//                {
//                    cout << j << " " << pos << '\n';
//                }
                if(sum[pos] - sum[j-1] != sum[i])
                {
                    check = false;
                    break;
                } else
                {
                    j = pos+1;
                    cnt++;
                }
            }
            if(check)
            {
                res = max(res, cnt);
            }
        }
    }
    cout << res;
}

/*
9
1 2 3 6 3 3 2 4 5
*/
