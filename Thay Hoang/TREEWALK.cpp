#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "TREEWALK"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
ll sum = 1, cnt = 1;

int main()
{
    init();
    cin >> s;
    for(char c : s)
    {
        if(c == 'P') continue;
        if(c == '*')
        {
            sum *= 5;
            sum += cnt;
            sum %= MOD;
            cnt *= 3;
            cnt %= MOD;
        }
        else
        {
            sum *= 2;
            if(c == 'R') sum += cnt;
            sum %= MOD;
        }
    }
    cout << sum;
}

