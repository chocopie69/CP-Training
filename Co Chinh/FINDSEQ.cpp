#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "FINDSEQ"

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

ll n,s,a[SZ], sum[SZ];

int main()
{
    init();
    cin >> n >> s;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int oddJ = 2, evenJ = 3, len;
    ll s1, s2;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            if(oddJ <= i) oddJ = i+1;
            len = (oddJ - i + 1) / 2;
            s1 = sum[i+len-1] - sum[i-1];
            s2 = sum[oddJ] - sum[i+len-1];
            while(oddJ+2 <= n && s1 + a[i+len] <= s && s2 - a[i+len] + a[oddJ+1] + a[oddJ+2] <= s)
            {
                //cout << s1 << " " << s2 << " ";
                s1 = s1 + a[i+len];
                s2 = s2 - a[i+len] + a[oddJ+1] + a[oddJ+2];
                oddJ += 2;
                len = (oddJ - i + 1) / 2;
                //cout << s1 << " " << s2 << " " << i << " " << oddJ << '\n';
            }
            if(len*2 < 2 || s1 > s || s2 > s || oddJ > n)
            {
                cout << 0 << '\n'; //9852 8507
                continue;
            }
        } else
        {
            if(evenJ <= i) evenJ = i+1;
            len = (evenJ - i + 1) / 2;
            s1 = sum[i+len-1] - sum[i-1];
            s2 = sum[evenJ] - sum[i+len-1];
            while(evenJ+2 <= n && s1 + a[i+len] <= s && s2 - a[i+len] + a[evenJ+1] + a[evenJ+2] <= s)
            {
                s1 = s1 + a[i+len];
                s2 = s2 - a[i+len] + a[evenJ+1] + a[evenJ+2];
                evenJ += 2;
                len = (evenJ - i + 1) / 2;
            }
            if(len*2 < 2 || s1 > s || s2 > s || evenJ > n)
            {
                cout << 0 << '\n';
                continue;
            }
        }
        cout << len*2 << '\n';
    }
}

/*
11 6
3 2 1 9 3 4 2 1 3 1 2
*/
