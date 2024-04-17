#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CROWED"

using namespace std;

const int SZ = 5e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,d, res = 0;
pll a[SZ];
deque<ll> dq;
multiset<ll> low,up;

int main()
{
    init();
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    ll cur = 0;
    for(int i = 0; i < n; i++)
    {
        while(!dq.empty() && a[i].first > a[dq.front()].first + d)
        {
            low.erase(low.find(a[dq.front()].second));
            dq.pop_front();
        }
        while(cur < n && a[cur].first <= a[i].first + d)
        {
            up.insert(a[cur].second);
            cur++;
        }
        if(!low.empty() && !up.empty() && *low.rbegin() >= a[i].second * 2 && *up.rbegin() >= a[i].second * 2 )
            res++;
        low.insert(a[i].second);
        up.erase(up.find(a[i].second));
        dq.push_back(i);
    }
    cout << res;
}

/*
6 4
10 3
6 2
5 3
9 7
3 5
11 2
*/

