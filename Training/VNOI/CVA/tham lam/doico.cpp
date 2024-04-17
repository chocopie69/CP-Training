#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,b[LIMIT], res = 0;
multiset<int> s;
vector<int> v;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> b[i];
        s.insert(x);
    }
    sort(b,b+n);
    for(int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(b[i]);
        if(it != s.begin())
        {
            it--;
            res += 2;
            s.erase(it);
        } else
        {
            v.push_back(b[i]);
        }
    }
    for(int i : v)
    {
        auto it = s.lower_bound(i);
        if(*it == i)
        {
            res++;
            s.erase(it);
        }
    }
    cout << res;
}
