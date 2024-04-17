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

int t,n,a[SZ], maxNum = -INF, maxNum2 = -INF, pos1, pos2;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        maxNum = -INF;
        maxNum2 = -INF;
        for(int i = 1; i <= n-1; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                if(__gcd(a[i],a[j]) > maxNum)
                {
                    maxNum = max(maxNum, __gcd(a[i], a[j]));
                    pos1 = i;
                    pos2 = j;
                }
            }
        }
//        for(int i = 1; i <= n; i++)
//        {
//            if(i == pos1 || i == pos2) continue;
//            maxNum2 = max(maxNum2, __gcd(a[pos1], a[i]));
//        }
//        for(int i = 1; i <= n; i++)
//        {
//            if(i == pos2 || i == pos1) continue;
//            maxNum2 = max(maxNum2, __gcd(a[pos2], a[i]));
//        }
        for(int i = 1; i <= n-1; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                if(__gcd(a[i],a[j]) > maxNum2 && (i != pos1 || j != pos2))
                {
                    maxNum2 = max(maxNum2, __gcd(a[i], a[j]));
                }
            }
        }
        //cout << pos1 << " " << pos2 << " ";
        cout << maxNum2 << '\n';
    }
}
