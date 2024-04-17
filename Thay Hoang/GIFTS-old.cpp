#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxMN = 1e6+5;

int m,n;
ll a[maxMN],b[maxMN],ptr[maxMN],res=0;
bool bought[maxMN],hasPrize[maxMN];

int main()
{
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(bought,false,sizeof(bought));
    memset(ptr,0,sizeof(ptr));
    memset(hasPrize,false,sizeof(hasPrize));
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        hasPrize[b[i]] = true;
    }
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        ll cnt = 0;
        while(ptr[a[i]] <= 1e6)
        {
            ptr[a[i]] += a[i];
            if(ptr[a[i]] > 1e6) break;
            if(bought[ptr[a[i]]] == false)
            {
                bought[ptr[a[i]]] = true;
                if(hasPrize[ptr[a[i]]]) res++;
                cnt++;
                if(cnt == a[i]) break;
            }
        }
    }
    cout << res;
}
