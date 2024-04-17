#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,res = 0,x;
multiset<int> ms1, ms2;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x > 0) ms1.insert(x);
        else ms2.insert(-x);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x > 0)
        {
            auto it = ms2.upper_bound(x);
            if(it != ms2.end())
            {
                res++;
                ms2.erase(it);
            }
        }
        else
        {
            auto it = ms1.lower_bound(-x);
            if(it != ms1.begin())
            {
                res++;
                ms1.erase(--it);
            }
        }
    }
    cout << res;
}
