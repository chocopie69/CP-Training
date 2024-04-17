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

int n,x;
set<int> s,sum;

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> x;
        s.insert(x);
        if(s.size() == 1) cout << 0 << '\n';
        else
        {
            set<int>::iterator it = s.lower_bound(x);
            if(it == s.begin())
            {
                sum.insert(*(++it) - *it);
            }
            else if(it == (--s.end()))
            {
                sum.insert(*it - *(--it));
            }
            else
            {
                set<int>:: iterator it1 = it, it2 = it;
                it1++,it2--;
                sum.erase(*it1 - *it2);
                sum.insert(*it1 - *it);
                sum.insert(*it - *it2);
            }
            cout << *(--sum.end()) << '\n';
        }
    }
}

