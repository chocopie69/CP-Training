#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "S4"

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

ll tongcs(ll x)
{
    ll sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

ll c,n, nextC;

int main()
{
    init();
    cin >> c >> n;
    n--;
    while(n--)
    {
        nextC = c+1;
        ll prev = tongcs(c*4), k = 10, x = 0, digit, digit2;
        while(tongcs(nextC) != prev)
        {
            if(tongcs(nextC) < prev)
            {
                digit = ( ((nextC % k) - x) / (k/10));
                //if(c == 17) cout << digit << " " << nextC << ' ';
                if(prev - tongcs(nextC) > 9 - digit)
                {
                    nextC += (9-digit) * (k/10);
                } else
                {
                    nextC += (prev-tongcs(nextC)) * (k/10);
                }
                //if(c == 17) cout << nextC << '\n';
                k *= 10;
                x = x*10 + 9;
            } else
            {
                digit = ((nextC % k) / (k/10));
                //digit2 = max((nextC % (k * 10)) / k,1LL);
                nextC += k;
                nextC -= digit*(k/10);
//                if(c == 65)
//                {
//                    cout << digit << " " << digit2 << " " << nextC << " " << k << '\n';
//                }
                k *= 10;
                if(tongcs(nextC) < prev)
                {
                    k = 10;
                    x = 0;
                }
            }
        }
        c = nextC;
        cout << c << '\n';
    }
    //cout << c;
}
