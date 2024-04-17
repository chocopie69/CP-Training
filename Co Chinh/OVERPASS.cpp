#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "OVERPASS"

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

int n, cntL = 0, l[SZ], r[SZ];
string s;

int main()
{
    init();
    cin >> n >> s;
    s = " " + s;
    l[0] = 0;
    r[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 'L')
        {
            l[i] = min(l[i-1] + 1, r[i-1] + 1);
            r[i] = min(l[i-1] + 1, r[i-1]);
        } else if(s[i] == 'R')
        {
            l[i] = min(l[i-1], r[i-1] + 1);
            r[i] = min(l[i-1] + 1, r[i-1] + 1);
        } else
        {
            l[i] = min(l[i-1] + 1, r[i-1] + 2);
            r[i] = min(l[i-1] + 2, r[i-1] + 1);
        }
    }
    cout << min(l[n] + 1, r[n]);
}

