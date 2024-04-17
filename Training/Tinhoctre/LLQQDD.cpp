#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,k,cntL[SZ],cntQ[SZ],cntD[SZ], res = INF, L[SZ], D[SZ];
string s;

int main()
{
    init();
    cin >> n >> k >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        cntL[i] = cntL[i-1] + int(s[i] == 'L');
        cntQ[i] = cntQ[i-1] + int(s[i] == 'Q');
        cntD[i] = cntD[i-1] + int(s[i] == 'D');
    }
    memset(L,-1,sizeof(L));
    memset(D,-1,sizeof(D));
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        while(j < i && cntL[i] - cntL[j] >= k) j++;
        if(cntL[i] - cntL[j-1] >= k)
        {
            //cout << i << " " << j << '\n';
            L[i] = j;
        }
    }
    j = n;
    for(int i = n; i >= 1; i--)
    {
        while(j > i && cntD[j-1] - cntD[i-1] >= k) j--;
        if(cntD[j] - cntD[i-1] >= k)
        {
            //cout << i << " " << j << '\n';
            D[i] = j;
        }
    }
    j = 1;
    for(int i = 1; i <= n; i++)
    {
        while(j < i && cntQ[i] - cntQ[j] >= k) j++;
        if(cntQ[i] - cntQ[j-1] >= k && L[j-1] != -1 && D[i+1] != -1)
        {
            //cout << i << " " << j << '\n';
            res = min(res,D[i+1]-L[j-1]+1 - 3*k);
        }
    }
    cout << (res == INF ? -1 : res);
}

