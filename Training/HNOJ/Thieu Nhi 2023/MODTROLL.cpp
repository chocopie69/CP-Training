#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string a;
ll b;

int main()
{
    init();
    cin >> a >> b;
    ll m = 0;
    for(char c : a)
    {
        m = m * 10 + (int(c) - 48);
        if(m >= b)
        {
            m %= b;
        }
    }
    cout << m;
}

