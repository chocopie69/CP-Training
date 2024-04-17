#include<bits/stdc++.h>
using namespace std;
string s;

void phi(long long n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int dem=0;
            while(n%i==0)
            {
                dem++;
                n/=i;
            }
            cout << i << "^" << dem;
            if(n != 1) cout << " * ";
        }
    }
    if(n!=1)
    {
        cout << n << "^1";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    phi(n);
}
