#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "REPSTR"

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

string s;
int lenS, f[SZ], q;

int main()
{
    init();
    cin >> s;
    lenS = s.length();
    s = " " + s;
    f[1] = 0;
    q = 0;
    for(int i = 2; i <= lenS; i++)
    {
        while(q > 0 && s[q+1] != s[i])
        {
            q = f[q];
        }
        if(s[q+1] == s[i]) q++;
        f[i] = q;
    }
    cout << s.substr(1, lenS - f[lenS]);
}

