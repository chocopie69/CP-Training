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

int q, type, y;
string x;
map<string,int> mp;

int main()
{
    init();
    cin >> q;
    while(q--)
    {
        cin >> type >> x;
        if(type == 1)
        {
            cin >> y;
            mp[x] += y;
        }
        else if(type == 2)
        {
            mp[x] = 0;
        }
        else
        {
            cout << mp[x] << '\n';
        }
    }
}

