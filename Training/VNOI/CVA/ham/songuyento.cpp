#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll maxPrime = 3e6+5;
ll n,k;
vector<ll> prime;
bool isPrime[maxPrime+5];

void sang()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i=2;i*i<=maxPrime;i++)
    {
        if(isPrime[i]) for(ll j=i*i;j<=maxPrime;j+=i)
        {
            isPrime[j] = false;
        }
    }
    for(l i=2;i<=maxPrime;i++) if(isPrime[i]) prime.push_back(i);
}

int main()
{
    int t;
    cin >> t;
    sang();
    //for(int i=0;i<prime.size();i++) cout << prime[i] << '\n';
    while(t--)
    {
        cin >> n >> k;
        int l = 0, r = prime.size() - k + 1;
        ll res=-1;
        while(l <= r) {
           int mid = (l+r)/2;
           ll tich = 1;
           bool flag = false;
           for(int i=mid;i<mid+k;i++)
           {
               if(n/tich >= prime[i]) tich *= prime[i];
               else flag = true;
           }
           if(tich <= n && !flag) {
                l = mid+1;
                res=tich;
           } else {
               r = mid-1;
            }
        }
        cout << res << '\n';
    }
}
