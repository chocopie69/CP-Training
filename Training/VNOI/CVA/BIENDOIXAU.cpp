#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BIENDOIXAU"

using namespace std;

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,d, res = INF;
string a[SZ], s;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    d = s.length();
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        bool fucked = false;
        for(int k = 0; k < d; k++)
        {
            if(a[i][k] == s[k]) continue;
            bool flag = false;
            for(int j = 1; j <= n; j++)
            {
                if(a[j][k] == s[k])
                {
                    flag = true;
                    break;
                }
            }
            if(flag) cnt++;
            else fucked = true;
        }
        if(fucked) continue;
        res = min(res, cnt);
    }
    cout << res;
}

/*
3
abc
cab
bca
acb
*/

