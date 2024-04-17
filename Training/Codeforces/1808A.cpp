/// https://codeforces.com/contest/1808/problem/A

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

int t,lo,hi,pow10[LIMIT];

int main()
{
    init();
    cin >> t;
    pow10[0] = 1;
    for(int i = 1; i <= 8; i++)
    {
        pow10[i] = pow10[i-1]*10;
        //cout << pow10[i] << '\n';
    }
    while(t--)
    {
        cin >> lo >> hi;
        for(int i = 9; i >= 1; i--)
        {
            if(lo <= i && i <= hi)
            {
                cout << i << '\n';
                return 0;
            }
        }
        for(int res = 9; res >= 0; res--)
        {
            bool found = false;
            for(int i = 0; i + res <= 9; i++)
            {
                int j = i + res, idx = 1;
                bool flag = false;
                if(j != 0)
                {
                    while(j*pow10[idx] + i <= hi)
                    {
                        if(j*pow10[idx] + i >= lo)
                        {
                            flag = true;
                            //cout << j*pow10[idx] + i << '\n';
                            break;
                        }
                        idx++;
                    }
                }
                if(flag)
                {
                    cout << j*pow10[idx] + i << '\n';
                    found = true;
                    break;
                }
                flag = false;
                if(i != 0)
                {
                    while(i*pow10[idx] + j <= hi)
                    {
                        if(i*pow10[idx] + j >= lo)
                        {
                            flag = true;
                            //cout << i*pow10[idx] + j << '\n';
                            break;
                        }
                        idx++;
                    }
                }
                if(flag)
                {
                    cout << i*pow10[idx] + j << '\n';
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
    }
}

