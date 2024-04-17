#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CLASSROOM"

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

ll ncr[5005][5005], t,a,b;

void preCompute()
{
	int k;
	for (int i = 0; i < 5001; i++)
	{
		ncr[i][0] = ncr[i][i] = 1;
		k = i >> 1;
		for (int j = 1; j < k + 1; j++)
			ncr[i][j] = ncr[i][i - j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
	}
}

int main()
{
    init();
    preCompute();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        ll res = 1;
        for(int i = 1; i <= a; i++)
        {
            res += ncr[b][i];
        }
        cout << res;
    }
}
