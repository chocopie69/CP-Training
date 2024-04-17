#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 2e5+5;
const ll INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin);
    ///freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,res=0;
string s1, s2;
map<string,int> mp;

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> s1 >> s2;
        s1 = s1.substr(0,2);
        if(s1 == s2) continue;
        res += mp[s2+s1];
        mp[s1+s2]++;
    }
    cout << res;
}
