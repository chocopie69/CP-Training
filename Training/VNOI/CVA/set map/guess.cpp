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

int n,m,x;
set<int> s;
int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        s.insert(x);
        set<int>::iterator it = s.lower_bound(x);
        set<int>::iterator it1 = it, it2 = it;
        if(it != s.begin())
        {
            it1--;
            if(x - (*it1) < m)
            {
                cout << i;
                return 0;
            }
        }
        if(++it != s.end())
        {
            it2++;
            if((*it2) - x < m)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
}

