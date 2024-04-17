#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
long long n,prime[maxN+5];
vector<long long> primes;

void sang()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(long long i=2;i*i*i*i<=n;i++)
    {
        if(prime[i]) for(long long j=i*i;j*j<=n;j+=i)
        {
            prime[j] = false;
        }
    }
    for(long long i=2;i*i<=n;i++) if(prime[i]) primes.push_back(i);
}

bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    sang();
    bool flag = false;
    for(int i=0;i<primes.size()-1;i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            long long z = primes[i]*primes[i] + primes[j]*primes[j];
            if(z <= n && isPrime(z))
            {
                cout << primes[i] << " " << primes[j] << " " << z << '\n';
                flag = true;
            }
        }
    }
    if(flag == false) cout << -1;
}
