#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "REPLACE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s,t;
int n,m, sumS[SZ], res1, res2, mx = 0;

int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    s = " " + s;
    t = " " + t;
    int hiS = n+1, hiT = m+1;
    while(min(hiS,hiT) > 1 && s[hiS-1] == t[hiT-1])
    {
        hiS--;
        hiT--;
    }
    int lo = 0;
    while(lo < min(m,n) && s[lo+1] == t[lo+1])
    {
        lo++;
    }
    sumS[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sumS[i] = sumS[i-1] + int(s[i]) - 48;
    }
    //cout << lo << " " << hiS << " " << hiT << '\n';
    for(int i = 1; i <= min(lo + 1,m); i++)
    {
        string cur = "";
        for(int j = i; j <= min(i+6,m); j++)
        {
            cur += t[j];
            if(j < hiT-1) continue;
            int x = stoi(cur);
            int pos = n - (m-j);
            if(pos < hiS - 1) continue;
            if(sumS[pos] - sumS[i-1] == x)
            {
                if(pos-i+1 > mx)
                {
                    mx = pos-i+1;
                    res1 = i;
                    res2 = pos;
                }
            }
            if(t[i] == '0') break;
        }
    }
    cout << res1 << " " << res2;
}
