#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ], len1[SZ], len2[SZ], len3, len4, mx1 = 0, mx2 = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    len1[1] = len2[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i-1])
        {
            len1[i] = len1[i-1] + 1;
            len2[i] = 1;
        } else if(a[i] < a[i-1])
        {
            len1[i] = 1;
            len2[i] = len2[i-1] + 1;
        } else
        {
            len1[i] = len2[i] = 1;
        }
    }
    len3 = len4 = 1;
    for(int i = n-1; i >= 1; i--)
    {
        if(a[i] > a[i+1])
        {
            len3++;
            len4 = 1;
            if(len3 > 1 && len1[i] > 1) mx1 = max(mx1, min(len1[i]-1, len3 - 1));
        } else if(a[i] < a[i+1])
        {
            len3 = 1;
            len4++;
            if(len4 > 1 && len2[i] > 1) mx2 = max(mx2, min(len2[i]-1, len4 - 1));
        } else
        {
            len3 = len4 = 1;
        }
        //cout << i << " " << len1[i] << " " << len3 << " " << len2[i] << " " << len4 << '\n';
    }
    cout << mx1 << " " << mx2;
}

