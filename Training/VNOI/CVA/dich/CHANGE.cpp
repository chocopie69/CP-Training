#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CHANGE"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s, res = "12345678";

int main()
{
    init();
    cin >> s;
    for(char c : s)
    {
        if(c == 'L')
        {
            char cur = res[0];
            res.erase(0,1);
            res = res + cur;
        }
        else
        {
            char cur = res[7];
            res.erase(7,1);
            res = cur + res;
        }
    }
    cout << res;
}