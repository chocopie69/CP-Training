#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CLASSIFY"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[LIMIT],b[LIMIT], res = 0;
string s;

int getCode(char c)
{
    if(c == 'A') return 1 << 0;
    else if(c == 'C') return 1 << 1;
    else if(c == 'G') return 1 << 2;
    else return 1 << 3;
}

int main()
{
    init();
    cin >> n >> m;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
            a[j] |= getCode(s[j]);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < m; j++)
            b[j] |= getCode(s[j]);
    }
    for(int i = 0; i < m; i++)
    {
        if((a[i] & b[i]) == 0) res++;
    }
    cout << res;
}

