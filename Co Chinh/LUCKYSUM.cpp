#include <bits/stdc++.h>
#define ll unsigned long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LUCKYSUM"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll lo,hi;
vector<ll> vec;
queue<ll> qu;

ll res(ll x)
{
    ll prev = 0, sum = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] < x)
        {
            sum += vec[i] * (vec[i] - prev);
            prev = vec[i];
        } else
        {
            sum += vec[i] * (x - prev);
            break;
        }
    }
    return sum;
}

int main()
{
    init();
    qu.push(4);
    qu.push(7);
    while(!qu.empty())
    {
        ll x = qu.front();
        qu.pop();
        vec.push_back(x);
        if(x * 10 + 4 <= 1e10) qu.push(x * 10 + 4);
        if(x * 10 + 7 <= 1e10) qu.push(x * 10 + 7);
    }
    cin >> lo >> hi;
    cout << res(hi) - res(lo-1);
}
