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

int n,a[LIMIT];
set<int> s;
map<int,int> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    auto it = s.begin();
    for(int i = 1; i <= s.size(); i++)
    {
        mp[*it] = i;
        it++;
    }
    for(int i = 0; i < n; i++)
    {
        cout << mp[a[i]] << " ";
    }
}

