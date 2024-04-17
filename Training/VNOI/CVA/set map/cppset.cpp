#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int type,x;
set<int> s;

int main()
{
    init();
    while(cin >> type)
    {
        if(type == 0) return 0;
        if(type != 3 && type != 4)
            cin >> x;
        if(type == 1)
            s.insert(x);
        if(type == 2 && !s.empty())
            s.erase(x);
        if(s.empty() && type != 2)
        {
            cout << "empty" << '\n';
            continue;
        }
        if(type == 3)
            cout << *s.begin() << '\n';
        if(type == 4)
            cout << *(--s.end()) << '\n';
        if(type == 5)
        {
            auto it = s.upper_bound(x);
            if(it == s.end()) cout << "no" << '\n';
            else cout << *it << '\n';
        }
        if(type == 6)
        {
            auto it = s.lower_bound(x);
            if(it == s.end()) cout << "no" << '\n';
            else cout << *it << '\n';
        }
        if(type == 7)
        {
            auto it = s.lower_bound(x);
            if(it == s.begin()) cout << "no" << '\n';
            else cout << *(--it) << '\n';
        }
        if(type == 8)
        {
            auto it = s.upper_bound(x);
            if(it == s.begin()) cout << "no" << '\n';
            else cout << *(--it) << '\n';
        }
    }
}

