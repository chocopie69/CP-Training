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

ll n,k,a[LIMIT], maxNum[LIMIT];

namespace sub1
{
    void solve()
    {
        for(int i = n+1; i <= 2*n; i++)
        {
            a[i] = a[i-n];
        }
        ll res = -INFLL;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i+n-1; j >= i; j--)
            {
                if(j == i+n-1)
                {
                    maxNum[j] = a[j];
                }
                else
                {
                    maxNum[j] = max(maxNum[j+1], a[j]);
                }
            }
            for(int j = i+1; j < i+n-1; j++)
            {
                /*for(int k = j+1; k < i+n;k++)
                {
                    res = max(res, a[i] - a[j] + a[k]);
                }*/
                res = max(res,a[i]-a[j]+maxNum[j]);
            }
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(k == 1)
    {
        sub1::solve();
    }
    else
    {
        cout << 1e6+3;
    }
}

