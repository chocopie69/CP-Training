#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e6+2;
int m,l,r,ans[LIMIT];
bool prime[LIMIT];

void sang()
{
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i < LIMIT;i++)
    {
        if(prime[i]) for(int j=i*i;j<LIMIT;j+=i)
        {
            prime[j] = false;
        }
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(prime,true,sizeof(prime));
    memset(ans,0,sizeof(prime));
}

int main()
{
    init();
    sang();
    for(int i=1;i<LIMIT;i++)
    {
        ans[i] = ans[i-1] + prime[i];
    }
    cin >> m;
    while(m--)
    {
        cin >> l >> r;
        cout << ans[r] - ans[l-1] << '\n';
    }
}
