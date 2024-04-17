#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CLIST"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,l,a, t;
ull x;
deque<ll> dq;

int main()
{
    init();
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        dq.push_back(a);
    }
    cin >> x;
    x %= n;
    if(k > l)
    {
        t = x * ((k-l) % n);
        t %= n;
        while(t--)
        {
            ll cur = dq.front();
            dq.push_back(cur);
            dq.pop_front();
        }
    } else
    {
        t = x * ((l-k) % n);
        t %= n;
        while(t--)
        {
            ll cur = dq.back();
            dq.push_front(cur);
            dq.pop_back();
        }
    }
    while(!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}
