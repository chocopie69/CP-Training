#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "HCN"

using namespace std;

const int SZ = 1e6+5, SZ2 = 305;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime[SZ];
vector<int> primes;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i) isPrime[j] = false;
    }
    for(int i = 2; i < SZ; i++)
    {
        if(isPrime[i]) primes.push_back(i);
    }
}

ll a[SZ2][SZ2],n,m, cnt1,cnt2, res = 0;

int main()
{
    init();
    sieve();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            cnt1 = 0;
            cnt2 = 0;
            for(int k = 1; k <= n; k++)
            {
                if(isPrime[a[k][i]] && isPrime[a[k][j]])
                {
                    res += cnt1+cnt2;
                    cnt1++;
                } else if(isPrime[a[k][i]] || isPrime[a[k][j]])
                {
                    res += cnt1;
                    cnt2++;
                }

            }
        }
    }
    cout << res;
}

/*
3 4
1 2 3 4
1 2 3 4
1 4 3 5
*/
