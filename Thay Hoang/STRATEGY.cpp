#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "STRATEGY"

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

ll n1, n2, k, prev1, prev2;

int main()
{
    init();
    cin >> n1 >> n2 >> k;
    if(k == 1)
    {
        cout << n1;
        return 0;
    }
    if(k == 2)
    {
        cout << n2;
        return 0;
    }
    k -= 2;
    prev1 = n1;
    prev2 = n2;
    if(n1 >= n2*2)
    {
        ll cur = (n1-n2-1) / (n2*3) + 1;
        if(k <= cur*3)
        {
            if(k % 3 == 0)
            {
                cout << n2;
                return 0;
            }
            else
            {
                ll cnt = (k-1)/3;
                ll res = n1-n2-n2*cnt;
                if(k % 3 == 2) res -= n2;
                cout << res;
                return 0;
            }
        }
        else
        {
            ll cnt = (3*(cur-1))/3;
            k -= cur*3;
            prev1 = n1-n2-n2*2*(cur-1)-n2;
            prev2 = n2;
        }
    }
    else if(n2 >= n1*2)
    {
        ll cur = (n2-n1-1) / (n1*3) + 1;
        if(k <= cur*3)
        {
            if(k % 3 == 0)
            {
                cout << n1;
                return 0;
            }
            else
            {
                ll cnt = (k-1)/3;
                ll res = n2-n1-n1*cnt;
                if(k % 3 == 2) res -= n1;
                cout << res;
                return 0;
            }
        }
        else
        {
            k -= cur*3;
            prev1 = n2-n1-n1*2*(cur-1)-n1;
            prev2 = n1;
        }
    }
    ll res;
    while(prev1 != prev2)
    {
        res = abs(prev1-prev2);
        prev1 = prev2;
        prev2 = res;
        k--;
        if(k == 0)
        {
            cout << res;
            return 0;
        }
    }
    if(k % 3 == 1)
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << prev1;
        return 0;
    }
}

