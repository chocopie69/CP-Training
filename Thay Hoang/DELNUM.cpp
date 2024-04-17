#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DELNUM"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int m,n,a[LIMIT],b[LIMIT],res = 0;
map<int,int> mp1, mp2;

int main()
{
    init();
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
        mp1[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp2[b[i]]++;
    }
    for(auto p : mp1)
    {
        if(mp2.find(p.first) != mp2.end())
        {
            res += min(p.second,mp2[p.first]);
        }
    }
    cout << res;
}

