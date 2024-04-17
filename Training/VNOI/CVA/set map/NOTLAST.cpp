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
    ///freopen(TASKNAME".INP","r",stdin);
    ///freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,x;
map<string,int> mp;
vector<pair<int,string>> v;
string s;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> x;
        mp[s] += x;
    }
    if(mp.size() != 7) v.push_back({0,"wysi"});
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back({it->second, it->first});
    }
    sort(v.begin(),v.end());
    for(int i = 1; i < v.size(); i++)
    {
        auto p = v[i];
        if(v[i].first > v[0].first)
        {
            cout << (i < v.size() - 1 && v[i].first == v[i+1].first ? "Tie" : v[i].second);
            return 0;
        }
    }
    cout << "Tie";
}

