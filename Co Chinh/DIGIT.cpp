#include <bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DIGIT"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int t;
ll a,b,k;

ll multi(ll a, ll n, ll m)
{
    if(n == 0) return 0;
    ll cur = multi(a, n/2, m);
    cur = (cur + cur) % m;
    if(n % 2 == 0)
        return cur;
    return (cur + a % m) % m;
}

ll power(ll a, ll n, ll m)
{
    if(n == 0) return 1 % m;
    ll cur = power(a,n/2,m);
    cur = multi(cur,cur,m);
    if(n % 2 == 0)
        return cur % m;
    else
        return multi(cur % m,a % m, m);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        a = a % b;
        a = multi(a,power(10,k-1,b),b);
        cout << (a * 10) / b << '\n' ;
    }
}

