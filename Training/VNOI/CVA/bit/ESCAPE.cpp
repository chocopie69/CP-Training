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

int n,a[SZ],d[10], cnt, res = 0;
bool flag;

bool valid(int x)
{
    int i = 0;
    while(x > 0)
    {
        d[i] += (x % 10);
        x /= 10;
        if(d[i] >= 10) return false;
        i++;
    }
    return true;
}

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int x = 0; x < (1 << n); x++)
    {
        cnt = 0;
        flag = false;
        memset(d,0,sizeof(d));
        for(int k = 0; k < n; k++)
        {
            if( (x >> k & 1) == 1)
            {
                cnt++;
                if(!valid(a[k])) flag = true;
                //cout << k << " ";
            }
        }
        //cout << '\n';
        if(!flag) res = max(res, cnt);
    }
    cout << res;
}
