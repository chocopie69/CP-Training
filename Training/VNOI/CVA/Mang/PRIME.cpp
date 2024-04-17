#include <bits/stdc++.h>
using namespace std;

const int maxN = 1002;
int n, a[maxN],cnt = 0, sum = 0;

bool prime(int x)
{
    if(x < 2) return false;
    for(int i=2;i<=sqrt(x);i++) if(x % i == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(prime(a[i]))
        {
            cnt++;
            sum += a[i];
        }
    }
    cout << cnt << " " << sum;
 }
