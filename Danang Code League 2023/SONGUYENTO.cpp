#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime[SZ];
int a,b,x,cnt = 0, res = -1;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i)
        {
            isPrime[j] = false;
        }
    }
}

int main()
{
    init();
    sieve();
    cin >> a >> b >> x;
    int lo = 1, hi = b-a+1, mid;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        cnt = 0;
        bool flag = false;
        for(int i = a; i <= b; i++)
        {
            if(isPrime[i]) cnt++;
            if(i >= a+mid-1)
            {
                if(i > a+mid-1 && isPrime[i-mid]) cnt--;
                if(cnt < x)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            res = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    cout << res;
}

