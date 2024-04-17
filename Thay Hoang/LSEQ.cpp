#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "LSEQ"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,cnt = 0, curCnt[SZ], res = 1, cur;
bool existed[SZ+SZ+5];
vector<int> v;

int main()
{
    init();
    cin >> n;
    memset(existed,false,sizeof(existed));
    memset(curCnt,0,sizeof(curCnt));
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x != 0)
        {
            if(!existed[x+SZ])
            {
                v.push_back(x);
                existed[x+SZ] = true;
            }
        } else
        {
            cnt++;
        }
    }
    if(v.empty())
    {
        cout << cnt;
        return 0;
    }
    v.push_back(-INF);
    sort(v.begin(),v.end());
//    cout << cnt << '\n';
//    for(int i : v)
//    {
//        cout << i << " ";
//    }
    int i = 1, j = 1;
    while(j < v.size())
    {
        curCnt[j] = curCnt[j-1];
        if(j > 1) curCnt[j] += (v[j] - v[j-1] - 1);
        while(curCnt[j] - curCnt[i] > cnt && i <= j) i++;
        if(curCnt[j] - curCnt[i] <= cnt)
        {
            if(v[j]-v[i] + 1 + cnt - (curCnt[j] - curCnt[i]) > res)
            {
                res = v[j]-v[i] + 1 + cnt - (curCnt[j] - curCnt[i]);
                //cout << v[i] << " " << v[j] << " " << curCnt[i] << " " << curCnt[j] << '\n';
            }
        }
        j++;
    }
    cout << res;
}

/*
10
2 0 2 3 4 0 6 9 0 0
*/

/*
2 3 4 0 6 0 0 9 0
*/

