#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 65536, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


ll seed,mul,add,n,k, res = 0,a[LIMIT];

multiset<ll> low,up;

void ins(ll x)
{
    if(low.empty())
    {
        low.insert(x);
        return;
    }
    ll curMed = *low.rbegin();
    if(x > curMed)
    {
        up.insert(x);
        if(up.size() > k / 2)
        {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else
    {
        low.insert(x);
        if(low.size() > (k+1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(ll x)
{
    if(up.find(x) != up.end())
    {
        up.erase(up.find(x));
    }
    else
    {
        low.erase(low.find(x));
    }
    if(low.empty() && !up.empty())
    {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

int main()
{
    init();
    cin >> seed >> mul >> add >> n >> k;
    a[1] = seed;
    for(int i = 2; i <= n; i++)
    {
        a[i] = (a[i-1]*mul + add) % MOD;
    }
    for(int i = 1; i <= k; i++)
    {
        ins(a[i]);
    }
    res = *low.rbegin();
    for(int i = k+1; i <= n; i++)
    {
        er(a[i-k]);
        ins(a[i]);
        res += *low.rbegin();
    }
    cout << res;
}
