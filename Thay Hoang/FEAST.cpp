#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FEAST"

using namespace std;

const int LIMIT = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll t,a,b,res = 0;
bool dp[LIMIT];
vector<ll> v;

int main()
{
    init();
    cin >> t >> a >> b;
    dp[0] = true;
    v.push_back(0);
    for(int x = 1; x <= t; x++)
    {
        dp[x] = (x >= a && dp[x-a]) || (x >= b && dp[x-b]);
        if(dp[x])
            v.push_back(x);
    }
    int j = v.size()-1;
    for(int i = 0; i < v.size(); i++)
    {
        while(v[i] / 2 + v[j] > t)
            j--;
        res = max(res, v[i] / 2 + v[j]);
    }
    cout << res;
}

