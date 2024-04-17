#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+2;
int n,res=0;
bool prime[MN+2];

void sang()
{
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=MN;i++)
    {
        if(prime[i]) for(int j=i*i;j<=MN;j+=i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    cin >> n;
    sang();
    for(int i=2;i<=n;i++)
    {
        if(prime[i]) res++;
    }
    cout << res;
}
