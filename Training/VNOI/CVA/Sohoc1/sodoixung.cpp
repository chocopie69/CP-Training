#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    int res=0;
    cin >> n;
    long long n1 = n,n2=0;
    while(n != 0)
    {
        n2 = n2*10 + n % 10;
        n = n / 10;
    }
    if(n1 == n2) cout << "YES";
    else cout << "NO";
}
