#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, res = INT_MAX, cnt;
vector<pii> v;
map<int,int> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,t;
        cin >> x >> t;
        v.push_back({x,t});
        mp[t]++;
    }
    cnt = mp.size();
    mp.clear();
    sort(v.begin(),v.end());
    int i = 0, j = 0;
    while(j < v.size())
    {
        //cout << v[j].first << " " << v[j].second << '\n';
        bool flag = false;
        mp[v[j].second]++;

        if(mp.size() >= cnt)
        {
            flag = true;
            while(i < j && mp[v[i].second] > 1)
            {
                mp[v[i].second]--;
                i++;
            }
        }
        if(flag)
            res = min(res,v[j].first - v[i].first);
        j++;
    }
    cout << res;
}

