#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "LANDS"

using namespace std;

const int LIMIT = 50+5, LIMITSUM = 6e6, MAXA = 2500000;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[LIMIT][LIMIT], sum[LIMIT][LIMIT], res = 0, cnt[LIMITSUM];
vector<int> sumRect;

void preComputation()
{
    memset(sum,0,sizeof(sum));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
}

int getSum(int xTop, int yTop, int xBottom, int yBottom)
{
    return sum[xBottom][yBottom] - sum[xTop-1][yBottom] - sum[xBottom][yTop-1] + sum[xTop-1][yTop-1];
}

void th1()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int xTop = 1; xTop <= i; xTop++)
            {
                for(int yTop = 1; yTop <= j; yTop++)
                {
                    cnt[getSum(xTop,yTop,i,j)+MAXA]++;
                    sumRect.push_back(getSum(xTop,yTop,i,j)+MAXA);
                }
            }
            for(int xBottom = i+1; xBottom <= n; xBottom++)
            {
                for(int yBottom = j+1; yBottom <= n; yBottom++)
                {
                    res += cnt[getSum(i+1,j+1,xBottom,yBottom)+MAXA];
                }
            }
            while(!sumRect.empty())
            {
                cnt[sumRect[sumRect.size()-1]] = 0;
                sumRect.pop_back();
            }
        }
    }
}

void th2()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int xTop = 1; xTop <= i; xTop++)
            {
                for(int yTop = j; yTop <= n; yTop++)
                {
                    cnt[getSum(xTop,j,i,yTop)+MAXA]++;
                    sumRect.push_back(getSum(xTop,j,i,yTop)+MAXA);
                }
            }
            for(int xBottom = i+1; xBottom <= n; xBottom++)
            {
                for(int yBottom = 1; yBottom <= j-1; yBottom++)
                {
                    res += cnt[getSum(i+1,yBottom,xBottom,j-1)+MAXA ];
                }
            }
            while(!sumRect.empty())
            {
                cnt[sumRect[sumRect.size()-1]] = 0;
                sumRect.pop_back();
            }
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    preComputation();
    memset(cnt,0,sizeof(cnt));
    th1();
    th2();
    cout << res;
}

