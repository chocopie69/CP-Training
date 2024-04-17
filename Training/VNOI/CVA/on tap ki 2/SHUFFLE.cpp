#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SHUFFLE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m, trai[SZ], phai[SZ], i, j, cur, cnt = 0;

int main()
{
    init();
    cin >> n >> m;
    memset(trai,0,sizeof(trai));
    memset(phai,0,sizeof(phai));
    for(int i = 1; i <= (int) 1e6; i++)
    {
        trai[i] = i-1;
        phai[i] = i+1;
    }
    phai[n] = 0;
    while(m--)
    {
        cin >> i >> j;
        int traiI = trai[i], phaiI = phai[i];
        //cout << trai[i] << " " << phai[i] << " " << trai[j] << " " << phai[j] << '\n';
        if(trai[j] != 0)
        {
            phai[trai[j]] = i;
        }
        trai[i] = trai[j];
        if(traiI != 0)
            phai[traiI] = phaiI;
        if(phaiI != 0)
            trai[phaiI] = traiI;
        phai[i] = j;
        trai[j] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(trai[i] == 0)
        {
            cur = i;
            break;
        }
    }
    while(cur != 0)
    {
        //cout << cur << " ";
        cnt++;
        cur = phai[cur];
    }
    cout << cnt - n;
}

/*
100000 16
7 1
6 2
5 3
4 8
4 7
1 10
3 4
4 5
7 1
5 9
772 1000
2000 340
2 1032
42 5002
20021 23023
340 99999
*/


