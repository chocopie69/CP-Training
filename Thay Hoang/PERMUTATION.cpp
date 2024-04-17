#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PERMUTATION"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[LIMIT],fact[LIMIT],y, x = 1;
bool exists[LIMIT];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> y;
    fact[0] = 1;
    for(int i = 1; i <= 20; i++)
    {
        fact[i] = fact[i-1]*i;
    }
    memset(exists,false,sizeof(exists));
    for(int i = 1; i <= n; i++)
    {
        ll cnt = 0;
        for(int j = 1; j < a[i]; j++)
        {
            if(!exists[j]) cnt++;
        }
        //cout << cnt*fact[n-i] << '\n';
        x += cnt*fact[n-i];
        exists[a[i]] = true;
    }
    cout << x << '\n';
    memset(exists,false,sizeof(exists));
    for(int i = 1; i <= n; i++)
    {
        ll cur = (y-1)/fact[n-i],cnt=0,j=1;
        for(; j <= n; j++)
        {
            if(!exists[j]) cnt++;
            if(cnt == cur+1)
            {
                exists[j] = false;
                cout << j << " ";
                break;
            }
        }
        exists[j] = true;
        y -= fact[n-i]*cur;
    }
}

