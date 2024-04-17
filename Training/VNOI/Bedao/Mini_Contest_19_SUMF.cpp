#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+9, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k, cnt1 = 0, cnt2 = 0, cnt3 = 0, res = 0, pow2[SZ];
string s;

void preCompute()
{
    pow2[0] = 1;
    for(int i = 1; i < SZ; i++)
    {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
}

int main()
{
    init();
    preCompute();
    cin >> n >> k >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '?') cnt1++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '?') cnt2++;
        else if(s[i] == '0') cnt3++;
        if(i >= k - 1)
        {
            if(i >= k)
            {
                if(s[i-k] == '?') cnt2--;
                else if(s[i-k] == '0') cnt3--;
            }
            if(cnt3 == 0)
            {
                res = (res + pow2[cnt1-cnt2]) % MOD;
                //cout << cnt1 << " " << cnt2 << '\n';
            }
        }
    }
    cout << res;
}

