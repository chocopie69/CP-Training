#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e3+2;
int n,m,h,maxRow[LIMIT],minRow[LIMIT],maxCol[LIMIT],minCol[LIMIT],res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maxRow[i] == minRow[i] && maxCol[j] == minCol[j]) res++;
        }
    }
    cout << res << '\n';
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--)
    {
        res=0;
        fill(maxRow,maxRow+LIMIT,-INT_MAX);
        fill(minRow,minRow+LIMIT,INT_MAX);
        fill(maxCol,maxCol+LIMIT,-INT_MAX);
        fill(minCol,minCol+LIMIT,INT_MAX);
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> h;
                maxRow[i] = max(maxRow[i],h);
                minRow[i] = min(minRow[i],h);
                maxCol[j] = max(maxCol[j],h);
                minCol[j] = min(minCol[j],h);
            }
        }
        solve();
    }
}
