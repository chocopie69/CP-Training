#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t,n;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n % 2 == 1 || n <= 2) cout << -1;
        else
        {
            n/=2;
            for(int i=1;i<=n/2;i++)
            {
                cout << i*(n-i) << " ";
            }
        }
        cout << '\n';
    }
}
