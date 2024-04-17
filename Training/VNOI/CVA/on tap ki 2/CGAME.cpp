#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define int long long

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,x, resA, resB;
deque<int> dq;

signed main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> x;
        dq.push_back(x);
    }
    int i = 0;
    while(!dq.empty())
    {
        if(dq.back() > dq.front())
        {
            if(i % 2 == 0) resA += dq.back();
            else resB += dq.back();
            dq.pop_back();
        }
        else
        {
            if(i % 2 == 0) resA += dq.front();
            else resB += dq.front();
            dq.pop_front();
        }
        i++;
    }
    cout << resA << " " << resB;
}
