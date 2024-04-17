#include <bits/stdc++.h>
using namespace std;

bool prime(long long x)
{
    if(x < 2) return false;
    for(long long i=2;i <= sqrt(x);i++) if(x % i == 0) return false;
    return true;
}

bool check(long long x)
{
    return sqrt(x) == int(sqrt(x)) && prime(int(sqrt(x)));
}

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0;i<n;i++) cin >> a[i];
    for(long long i=0;i<n;i++)
    {
        cout << (check(a[i]) ? "YES" : "NO") << endl;
    }
}
