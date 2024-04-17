#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll t,n,a,b,x[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        string res = "NO";
        cin >> n >> a >> b;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        sort(x + 1, x + n + 1);
        int lA, lB, rA, rB;
        bool flag = false, flagRes = true;
        for(int i = 1; i <= n; i++)
        {
            if(i == 1)
            {
                lA = x[i];
            } else
            {
                if(!flag)
                {
                    if(x[i]-lA <= a)
                    {
                        rA = x[i];
                    } else
                    {
                        lB = x[i];
                        flag = true;
                    }
                } else if(x[i]-lB > b)
                {
                    flagRes = false;
                }
            }
        }
        if(flagRes)
        {
            cout << "YES" << '\n';
            continue;
        }
        swap(a,b);
        flagRes = true;
        flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(i == 1)
            {
                lA = x[i];
            } else
            {
                if(!flag)
                {
                    if(x[i]-lA <= a)
                    {
                        rA = x[i];
                    } else
                    {
                        lB = x[i];
                        flag = true;
                    }
                } else if(x[i]-lB > b)
                {
                    flagRes = false;
                }
            }
        }
        if(flagRes) res = "YES";
        cout << res << '\n';
    }
}
