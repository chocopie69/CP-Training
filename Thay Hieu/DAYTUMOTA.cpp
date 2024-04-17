#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 5e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n, cnt[SZ], sum[SZ];

void preCompute()
{
    cnt[1] = 1;
    sum[1] = 1;
    cnt[2] = 2;
    sum[2] = 3;
    int i = 2, j = 2;
    while(i <= int(5e6))
    {
        i++;
        while(sum[j] < i) j++;
        cnt[i] = j;
        sum[i] = sum[i-1] + j;
    }
//    for(int i = 1; i <= 7; i++)
//    {
//        cout << i << " " << cnt[i] << " " << sum[i] << '\n';
//    }
}

int main()
{
    init();
    preCompute();
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll lo = 1, hi = 5e6+2, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            //cout << mid << " " << sum[mid] << " lmao\n";
            if(sum[mid] >= n)
            {
                hi = mid-1;
                //cout << mid << " lmao\n";
            } else
            {
                lo = mid+1;
            }
        }
        cout << lo << '\n';
    }
}
