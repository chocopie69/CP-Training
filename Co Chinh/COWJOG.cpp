#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "COWJOG"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, res = 1;
pii a[LIMIT];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = n-1; i >= 1; i--)
    {
        if(a[i].second <= a[i+1].second)
        {
            res++;
        }
        else
        {
            a[i].second = a[i+1].second;
        }
    }
    cout << res;
}

