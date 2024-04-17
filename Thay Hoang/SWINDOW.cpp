#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SWINDOW"

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

string s,t;
ll f[SZ],k, cnt = 0, lenS, lenT, sum[SZ];

void kmpS()
{
    f[1] = 0;
    ll q = 0;
    for(int i = 2; i <= lenS; i++)
    {
        while(q > 0 && s[q+1] != s[i])
        {
            q = f[q];
        }
        if(s[q+1] == s[i]) q++;
        f[i] = q;
    }
}

int main()
{
    init();
    getline(cin,t);
    getline(cin,s);
    cin >> k;
    lenS = s.length();
    lenT = t.length();
    s = " " + s;
    t = " " + t;
    if(lenS > k)
    {
        cout << 0;
        return 0;
    }
    kmpS();
    ll j = 0;
    sum[0] = 0;
    for(int i = 1; i <= lenT; i++)
    {
        sum[i] = sum[i-1];
        while(j > 0 && s[j+1] != t[i])
        {
            j = f[j];
        }

        if(s[j+1] == t[i]) j++;
        if(j == lenS)
        {
            sum[i]++;
            j = f[j];
        }
    }
    for(int i = k; i <= lenT; i++)
    {
        if(sum[i] - sum[i-k+lenS-1] > 0) cnt++;
    }
    cout << cnt;
}

