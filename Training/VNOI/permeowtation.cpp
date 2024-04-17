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

int n,a[SZ], b[SZ];
bool flag = false;
string res = "";

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(i < n) res += "a";
        else if(i == n)
        {
            if(a[n] == b[1])
            {
                res += "b";
                flag = true;
            }
            else res += "a";
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(flag)
        {
            if(i < n) res += "b";
            else res += "a";
        } else
        {
            res += "b";
        }
    }
    cout << res;
}

