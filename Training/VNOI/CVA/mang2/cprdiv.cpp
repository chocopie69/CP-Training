#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 60005;
int n,m,cnt[LIMIT+2],minPrime[LIMIT+2],res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void sang()
{
    memset(minPrime,0,sizeof(minPrime));
    for(int i=2;i*i<=LIMIT;i++)
    {
        if(minPrime[i] == 0) for(int j=i*i;j<=LIMIT;j+=i)
        {
            minPrime[j] = i;
        }
    }
    for(int i=2;i<=LIMIT;i++)
    {
        if(minPrime[i] == 0) minPrime[i] = i;
    }
}

void phanTichNT(int x, int y)
{
    int a = x;
    while(a != 1)
    {
        cnt[minPrime[a]] += y;
        a /= minPrime[a];
    }
}

void solve()
{
    sang();
    for(int i=max(m,n-m)+1;i<=n;i++)
    {
        phanTichNT(i,1);
    }
    for(int i=2;i<=min(m,n-m);i++)
    {
        phanTichNT(i,-1);
    }
    for(int i=2;i<LIMIT;i++)
    {
        if(cnt[i] > 0) res++;
    }
    cout << res;
}

int main()
{
    init();
    cin >> n >> m;
    solve();
}

/*
For tu 2-n, phan tich thua so nguyen to, cong so mu vao mang dem phan phoi
For tu 2 den m, 2 den n-m, phan tich thua so nguyen to, tru so mu vao dem phan phoi
For tu 2 den 60000, neu so mu cua i > 0 => res++
*/
