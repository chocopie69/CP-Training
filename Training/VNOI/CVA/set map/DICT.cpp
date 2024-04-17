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
int t,type;
string s;
map<string,int> mp;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> type >> s;
        if(type == 1)
            mp[s]++;
        else
            cout << mp[s] << '\n';
    }
}

