#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "GROBOT"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n,a[SZ], cnt[SZ], prime[SZ+2], res = 1, cntZero = 0;
vector<int> numbers;

void sieve()
{
    for(int i = 0; i < SZ; i++)
    {
        prime[i] = i;
    }
    for(int i = 2; i * i < SZ; i++)
    {
        if(prime[i] == i) for(int j = i * i; j < SZ; j += i)
        {
            if(prime[j] == j) prime[j] = i;
        }
    }
}

void phantich(int x)
{
    while(x != 1)
    {
        int cur = prime[x];
        cnt[cur]++;
        numbers.push_back(cur);
        res = max(res, cnt[cur]);
        int curCnt = 0;
        while(prime[x] == cur)
        {
            x /= prime[x];
            curCnt++;
        }
        //cout << cur << " " << curCnt << '\n';
    }
}

int main()
{
    init();
    cin >> t;
    sieve();
    while(t--)
    {
        cin >> n;
        res = 0;
        cntZero = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
            if(a[i] != 0)
                phantich(a[i]);
            else
                cntZero++;
            //cout << '\n';
        }
        cout << res + cntZero << '\n';
        while(!numbers.empty())
        {
            cnt[numbers.back()] = 0;
            numbers.pop_back();
        }
    }
}

