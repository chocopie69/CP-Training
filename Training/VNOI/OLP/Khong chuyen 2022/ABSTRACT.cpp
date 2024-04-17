#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1002;
int n,m,a[LIMIT][LIMIT],curMax,res=0;
bool visible[LIMIT][LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(visible,false,sizeof(visible));
}

int main()
{
    init();
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        curMax = -INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(a[i][j] > curMax && a[i][j] != 0)
            {
                curMax = a[i][j];
                visible[i][j] = true;
            }
        }
        curMax = -INT_MAX;
        for(int j=m-1;j>=0;j--)
        {
            if(a[i][j] > curMax && a[i][j] != 0)
            {
                curMax = a[i][j];
                visible[i][j] = true;
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        curMax = -INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i][j] > curMax && a[i][j] != 0)
            {
                curMax = a[i][j];
                visible[i][j] = true;
            }
        }
        curMax = -INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i][j] > curMax && a[i][j] != 0)
            {
                curMax = a[i][j];
                visible[i][j] = true;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visible[i][j]) res++;
        }
    }
    cout << res;
}
