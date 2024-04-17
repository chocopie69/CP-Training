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

int n, res = INT_MAX;
vector<int> v1,v2,v3;
int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,t;
        cin >> x >> t;
        if(t == 1) v1.push_back(x);
        else if(t == 2) v2.push_back(x);
        else v3.push_back(x);
    }
    for(int x : v1)
    {
        int pos1 = lower_bound(v2.begin(),v2.end(),x) - v2.begin(),
            pos2 = lower_bound(v3.begin(),v3.end(),x) - v3.begin();
        if(pos1 >= v2.size() || pos2 >= v3.size()) break;
        res = min(res, max(v2[pos1],v3[pos2]) - x);
    }
    for(int x : v2)
    {
        int pos1 = lower_bound(v1.begin(),v1.end(),x) - v1.begin(),
            pos2 = lower_bound(v3.begin(),v3.end(),x) - v3.begin();
        if(pos1 >= v1.size() || pos2 >= v3.size()) break;
        res = min(res, max(v1[pos1],v3[pos2]) - x);
    }
    for(int x : v3)
    {
        int pos1 = lower_bound(v2.begin(),v2.end(),x) - v2.begin(),
            pos2 = lower_bound(v1.begin(),v1.end(),x) - v1.begin();
        if(pos1 >= v2.size() || pos2 >= v1.size()) break;
        res = min(res, max(v2[pos1],v1[pos2]) - x);
    }
    cout << res;
}
