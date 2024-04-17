#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,a[LIMIT], res;
map<int,int> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int left = 1, right = n;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        mp.clear();
        for(int i = 1; i <= mid; i++)
        {
            mp[a[i]]++;
        }
        for(int i = mid + 1; i <= n; i++)
        {
            if(mp.find(a[i]) != mp.end())
                mp[a[i]]++;
            mp[a[i-mid]]--;
            if(mp[a[i-mid]]  <= 0)
            {
                mp.erase(a[i-mid]);
            }
        }
        if(!mp.empty())
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << res;
}

