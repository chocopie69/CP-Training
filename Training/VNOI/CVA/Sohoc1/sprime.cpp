#include <bits/stdc++.h>
using namespace std;

const int maxAB = 1e7+2;
bool prime[maxAB+2];
int a,b;

void sang()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i<=maxAB;i++)
    {
        if(prime[i]) for(int j=i*i;j<=maxAB;j+=i)
        {
            prime[j] = false;
        }
    }
}

bool check(int x)
{
    int c = x;
    while(c != 0)
    {
        if(prime[c] == false) return false;
        c /= 10;
    }
    return true;
}

int main()
{
    int a,b;
    cin >> a >> b;
    sang();
    for(int i=a;i<=b;i++) if(check(i)) cout << i << endl;
}

