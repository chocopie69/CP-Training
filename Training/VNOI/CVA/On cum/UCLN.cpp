#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;

bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    init();
    cin >> n;
    if(n % 2 == 0)
    {
        cout << n/2;
    }
    else if(isPrime(n))
    {
        cout << 1;
    }
    else
    {
        for(int i = 2; i * i <= n; i++)
        {
            if(isPrime(i) && n%i == 0)
            {
                cout << n/i;
                return 0;
            }
        }
        cout << 1;
    }
}

