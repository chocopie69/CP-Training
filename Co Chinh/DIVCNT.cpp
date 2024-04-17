#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DIVCNT"

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

ll lo,hi, t;
ll isPrime[LIMIT];
bool flag[LIMIT];
vector<ll> primes;

void segmentedSieve(int lo, int range)
{
    memset(flag,false,sizeof(flag));
    for(int i = lo; i <= range; i++)
    {
        isPrime[i-lo] = 2;
    }
    for(ll i = 2; i * i <= range; i++)
    {
        ll t = (lo+i-1)/i;
        for(ll j = i*i ; j * j <= range; j*=i)
        {
            flag[j] = true;
        }
        //if(flag[i]) continue;
        for(ll j = max(i*i,i*t); j <= range; j+=i)
        {
            ll souoc = log(j)/log(i);
            //souoc--;
            souoc = 2;
            if(j == i*i) souoc--;
            //if(j/i)
            //cout << i << " " << j << " " << souoc << '\n';
            isPrime[j-lo] += souoc;
        }
    }
    if(1 >= lo) isPrime[1-lo] = 1;
    //if(0 >= lo) isPrime[0-lo] = false;
}

int main()
{
    init();
    t = 1;
    while(t--)
    {
        ll cnt = 0, first = -1, maxUoc = -INFLL;
        cin >> lo >> hi;
        segmentedSieve(lo, hi);
        for(int i = lo; i <= hi; i++)
        {
            maxUoc = max(maxUoc,isPrime[i-lo]);
        }
        for(int i = lo; i <= hi; i++)
        {
            if(isPrime[i-lo] == maxUoc)
            {
                if(first == -1) first = i;
                cnt++;
            }
        }
        //cout << isPrime[200] << '\n';
        cout << maxUoc << " " << first << " " << cnt << '\n';
    }
    /*ll souoc = log(81)/log(3);
    cout << souoc;*/
}


