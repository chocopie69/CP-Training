#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, res = 0;
        cin >> n;
        long long n1 = pow(n,3);
        for(long long i=n;i<sqrt(n1);i+=n)
        {
            if(n1 % i == 0)
            {
                long long cur = n1/i;
                if(__gcd(cur,i) == n) res += i + (n1/i);
            }
        }
        cout << res%MOD << '\n';
    }
}
