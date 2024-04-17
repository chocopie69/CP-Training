#include <bits/stdc++.h>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "Bai4"

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


ll n,m,k, len[SZ], price[SZ], sumLen[SZ], res = INFLL;
bitset<1005> needed, books[SZ], lmao;

clock_t start,rn;

double runningTime;

void recur(int pos, ll sum, ll cnt, bitset<1005> mask)
{
    if( (double) (clock() - start) > 0.96 * CLOCKS_PER_SEC)
    {
        cout << res;
        exit(0);
    }
    if(sum > res || cnt + (sumLen[n] - sumLen[pos-1]) < k ) return;
    if(pos == n+1)
    {
        if( (mask & needed) == needed ) res = min(res,sum);
        return;
    }
    recur(pos+1, sum + price[pos], cnt + len[pos], mask | books[pos]);
    recur(pos+1, sum, cnt, mask);
}

int main()
{
    init();
    cin >> n >> m >> k;
    sumLen[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i] >> len[i];
        for(int j = 1; j <= len[i]; j++)
        {
            ll x;
            cin >> x;
            books[i].set(x);
        }
        sumLen[i] = sumLen[i-1] + len[i];
    }
    for(int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        needed.set(x);
    }
    start = clock();
    recur(1,0,0,lmao);
    cout << res;
}

/*
4 6 4
5 2 1 3
8 3 1 4 5
3 3 2 4 5
6 3 1 5 6
1 2 3 4
*/
