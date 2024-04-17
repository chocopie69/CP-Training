#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MARBLES"

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
int n, sumB[SZ], sumR[SZ], res = 1;

int main()
{
    init();
    cin >> s;
    s += s;
    n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        sumB[i] = sumB[i-1] + (s[i] == 'b');
        sumR[i] = sumR[i-1] + (s[i] == 'r');
    }
    for(int i = 1; i <= n/2; i++)
    {
        int j = i + n/2 - 1;
        int lo = 1, hi = n/2, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(min(sumB[i+mid-1] - sumB[i-1],sumR[i+mid-1] - sumR[i-1]) == 0)
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        int gay = hi;
        lo = 1, hi = n/2-gay;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(min(sumB[j] - sumB[j-mid],sumR[j] - sumR[j-mid]) == 0)
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        res = max(res,hi + gay);
        //cout << hi << " " << gay << '\n';
    }
    cout << res;
}
