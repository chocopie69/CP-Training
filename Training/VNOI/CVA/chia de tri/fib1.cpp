#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll fibo[93],t;

void f()
{
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=92;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
}
char get(ll n,ll k)
{
    if(n==1)
    {
        return 'a';
    }
    if(n==2)
    {
        return 'b';
    }
    if(k<=fibo[n-2])
    {
        return get(n-2,k);
    }
    else return get(n-1,k-fibo[n-2]);
}

int main()
{
    init();
    cin >> t;
    f();
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        n++;
        cout << get(n,k) << '\n';
    }
}
