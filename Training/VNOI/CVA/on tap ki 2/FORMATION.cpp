#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m, trai[SZ], phai[SZ], type, i, j;

int main()
{
    init();
    cin >> n >> m;
    memset(trai,0,sizeof(trai));
    memset(phai,0,sizeof(phai));
    while(m--)
    {
        cin >> type >> i;
        if(type == 1 || type == 2) cin >> j;
        if(type == 1)
        {
            if(trai[j] != 0)
            {
                phai[trai[j]] = i;
                trai[i] = trai[j];
            }
            phai[i] = j;
            trai[j] = i;
        } else if(type == 2)
        {
            if(phai[j] != 0)
            {
                trai[phai[j]] = i;
                phai[i] = phai[j];
            }
            trai[i] = j;
            phai[j] = i;
        } else if(type == 3)
        {
            if(trai[i] != 0)
            {
                phai[trai[i]] = phai[i];
            }
            if(phai[i] != 0)
            {
                trai[phai[i]] = trai[i];
            }
            trai[i] = 0;
            phai[i] = 0;
        } else
        {
            cout << trai[i] << " " << phai[i] << '\n';
        }
    }
}

