#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NPERMUTE"

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

int n;

void recur(int i, string s)
{
    if(i == 0)
    {
        cout << s << '\n';
        return;
    }
    for(int j = 1; j <= n; j++)
    {
        bool flag = false;
        for(char c : s)
        {
            if(int(c) - 48 == j)
            {
                flag = true;
            }
        }
        if(!flag) recur(i-1, s + char(j+48) + " ");
    }
}

int main()
{
    init();
    cin >> n;
    recur(n, "");
}

