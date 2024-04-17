#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SOUOC"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll k,q,l,r, uoc[LIMIT+10], res[LIMIT + 10];

void sieve()
{
    uoc[1] = 1;
    for(int i = 2; i <= LIMIT; i++)
    {
        uoc[i] = 2;
    }
    for(int i = 2; i * 2 <= LIMIT; i++)
    {
        for(int j = i * 2; j <= LIMIT; j += i)
        {
            uoc[j]++;
        }
    } /// Dem uoc
}

void preComputation()
{
    res[0] = 1;
    for(int i = 1; i <= LIMIT; i++)
    {
        res[i] = res[i-1] + (uoc[i] >= k);
    } /// Tong cong don
}

int main()
{
    init();
    cin >> k >> q;
    sieve();
    preComputation();
    while(q--)
    {
        ll l,r;
        cin >> l >> r;
        cout << res[r] - res[l-1] << '\n';
    }

}

