#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin);
    //freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,sum = 0, res = 0;
pair<int,char> a[LIMIT];
map<int,int> mp, idx;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    for(int i = 0; i < n; i++)
    {
        if(a[i].second == 'B') sum++;
        else sum--;
        if(sum == 0)
            res = max(res, a[i].first - a[0].first)
        else
        {
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
            else
            {
                res = max(res,a[i].first - a[mp[sum] + 1].first);
            }
        }
    }
    cout << res;
}

